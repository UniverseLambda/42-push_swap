#include <ps_runtime.h>

#include <array.h>
#include <ops.h>
#include <limits.h>

enum	e_dir
{
	DIR_ROTATE,
	DIR_REVERSE
};

static int			get_max_below(t_lifo_stack *s, int val)
{
	size_t	i;
	int		curr_max;
	int		tmp;

	i = 0;
	curr_max = INT_MIN;
	while (i < s->elem_count)
	{
		tmp = lifo_at(s, i);
		if (curr_max < tmp && tmp < val)
			curr_max = tmp;
		++i;
	}
	return (curr_max);
}

// min: inclusive; max: exclusive
// Special case: when min == max, it will find the shortest way to min

static enum e_dir	nearest(t_lifo_stack *s, int min, int max)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = s->elem_count - 1;
	while (i < j)
	{
		if (min != max)
		{
			if (min <= s->data[i] && s->data[i] < max)
				return (DIR_REVERSE);
			if (min <= s->data[j] && s->data[j] < max)
				return (DIR_ROTATE);
		}
		else
		{
			if (s->data[i] == min)
				return (DIR_REVERSE);
			if (s->data[j] == min)
				return (DIR_ROTATE);
		}
		++i;
		--j;
	}
	return (DIR_ROTATE);
}

// min: inclusive; max: exclusive

t_bool	pushval(t_lifo_stack *sa, t_lifo_stack *sb)
{
	t_bool		is_highest;
	size_t		i;
	enum e_dir	dir;
	int			val;
	int			max;

	is_highest = FALSE;
	i = 0;
	val = lifo_at(sa, 0);
	while (i < sb->elem_count && !is_highest)
		if (lifo_at(sb, i) > lifo_at(sa, 0))
			is_highest = TRUE;
	if (!is_highest)
	{
		while (lifo_at(sb, 0) > val || lifo_at(sb, sb->elem_count - 1) > val)
			if (!rot_b())
				return (FALSE);
		return (push_b());
	}
	max = get_max_below(sb, val);
	dir = nearest(sb, max, max);
	while (lifo_at(sb, 0) != max)
		if ((dir == DIR_ROTATE && !rot_b()) || !rrot_b())
			return (FALSE);
	return (TRUE);
}

t_bool	handle_chunk(t_lifo_stack *sa, size_t chunk, size_t size)
{
	const int	min = chunk * size;
	const int	max = (chunk + 1) * size;
	enum e_dir	dir;
	int			i;
	t_bool		ret;

	i = min;
	while (i < max && i < (int)(rt_ptr()->stack_a.elem_count))
	{
		dir = nearest(sa, min, max);
		while (lifo_at(sa, 0) < min || lifo_at(sa, 0) >= max)
		{
			if (dir == DIR_ROTATE)
				ret = rot_a();
			else
				ret = rrot_a();
			if (!ret)
				return (FALSE);
		}
		push_b();
		++i;
	}
	return (TRUE);
}

#include <stdio.h>
t_bool	chunk_sort(t_runtime *rt)
{
	t_lifo_stack	*sa;
	size_t			curr;
	size_t			total;
	size_t			chunk_size;
	enum e_dir		dir;

	sa = &(rt->stack_a);
	curr = 0;
	chunk_size = (sa->elem_count / 5) + !!(sa->elem_count % 5);
	total = sa->elem_count / chunk_size + !!(sa->elem_count % chunk_size);
	while (curr < total)
	{
		if (!handle_chunk(sa, curr, chunk_size))
			return (FALSE);
		++curr;
	}
	int biggest = (int)(rt->stack_b.elem_count - 1);
	dir = nearest(&(rt->stack_b), biggest, biggest);

	printf("Looking for %d...\n", biggest);
	for (size_t i = 0; i < rt->stack_b.elem_count; ++i) {
		printf("[%zu]: %d\n", i, rt->stack_b.data[i]);
		if (rt->stack_b.data[i] == biggest) {
			printf("FOUND!!!!\n");
			break;
		}
	}

	while (lifo_at(&(rt->stack_b), 0) != biggest)
	{
		if (dir == DIR_ROTATE)
		{
			if (!rot_b())
			{
				return (FALSE);
			}
		}
		else if (!rrot_b())
			return (FALSE);
	}
	while (rt->stack_b.elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}