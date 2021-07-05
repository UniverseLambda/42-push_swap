#include <ps_runtime.h>

#include <array.h>
#include <ops.h>
#include <limits.h>


enum	e_dir
{
	DIR_NOT_FOUND,
	DIR_ROTATE,
	DIR_REVERSE
};

// min: inclusive; max: exclusive

static enum e_dir	nearest(t_lifo_stack *s, int max)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = s->elem_count - 1;
	while (i < j)
	{
		if (s->data[i] < max)
			return (DIR_REVERSE);
		if (s->data[j] < max)
			return (DIR_ROTATE);
		++i;
		--j;
	}
	if (i < s->elem_count && s->data[i] < max)
		return (DIR_ROTATE);
	return (DIR_NOT_FOUND);
}

static int	get_max(t_lifo_stack *s)
{
	size_t	i;
	int		curr_max;
	int		tmp;

	i = 0;
	curr_max = INT_MIN;
	while (i < s->elem_count)
	{
		tmp = s->data[i];
		if (tmp > curr_max)
			curr_max = tmp;
		++i;
	}
	return (curr_max);
}

static int	get_min(t_lifo_stack *s)
{
	size_t	i;
	int		curr_min;
	int		tmp;

	i = 0;
	curr_min = INT_MAX;
	while (i < s->elem_count)
	{
		tmp = s->data[i];
		if (tmp < curr_min)
			curr_min = tmp;
		++i;
	}
	return (curr_min);
}

t_bool	pushval(t_lifo_stack *sa, t_lifo_stack *sb)
{
	int			val;
	t_bool		higlow;
	int			mark;

	val = lifo_at(sa, 0);
	if (sb->elem_count <= 1)
	{
		if (sb->elem_count == 1 && lifo_at(sb, 0) > val)
			return (push_b() && rot_b());
		return (push_b());
	}
	higlow = (get_max(sb) < val) || (get_min(sb) > val);
	if (!higlow)
	{
		while (lifo_at(sb, 0) > val || sb->data[0] < val)
			if (!rot_b())
				return (FALSE);
		return (push_b());
	}
	mark = get_max(sb);
	while (lifo_at(sb, 0) != mark)
		if (!rot_b())
			return (FALSE);
	return (push_b());
}

t_bool	handle_chunk(t_lifo_stack *sa, t_lifo_stack *sb, int max)
{
	size_t		it;
	enum e_dir	dir;

	it = 0;
	dir = nearest(sa, max);
	while (dir != DIR_NOT_FOUND && it < rt_ptr()->stack_a.elem_count)
	{
		while (lifo_at(sa, 0) >= max)
		{
			if (dir == DIR_ROTATE && !rot_a())
				return (FALSE);
			if (dir == DIR_REVERSE && !rrot_a())
				return (FALSE);
			++it;
		}
		if (!pushval(sa, sb))
			return (FALSE);
		dir = nearest(sa, max);
	}
	return (TRUE);
}

t_bool	chunk_sort(t_runtime *rt)
{
	t_lifo_stack	*s[2];
	size_t			curr;
	size_t			total;
	size_t			remaining;
	size_t			chunk_size;

	s[0] = &(rt->stack_a);
	s[1] = &(rt->stack_b);
	curr = 0;
	total = 12;
	chunk_size = (s[0]->elem_count / total);
	remaining = (s[0]->elem_count % total);
	while (curr < total)
	{
		++curr;
		if (!handle_chunk(s[0], s[1], (curr * chunk_size) + remaining))
			return (FALSE);
	}
	int biggest = get_max(s[1]);
	while (lifo_at(s[1], 0) != biggest)
	{
		if (!rrot_b())
		{
			return (FALSE);
		}
	}
	while (s[1]->elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}