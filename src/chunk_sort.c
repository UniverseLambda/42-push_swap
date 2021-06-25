#include <ps_runtime.h>

#include <array.h>
#include <ops.h>
#include <limits.h>

static int	get_max(t_lifo_stack *s)
{
	size_t	i;
	int		curr_max;
	int		tmp;

	i = 0;
	curr_max = INT_MIN;
	while (i < s->elem_count)
	{
		tmp = lifo_at(s, i);
		if (curr_max < tmp)
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
		tmp = lifo_at(s, i);
		if (curr_min > tmp)
			curr_min = tmp;
		++i;
	}
	return (curr_min);
}

t_bool	pushval(t_lifo_stack *sa, t_lifo_stack *sb)
{
	int			val;
	t_bool		highest;
	t_bool		lowest;
	int			mark;

	val = lifo_at(sa, 0);
	if (sb->elem_count <= 1)
	{
		if (sb->elem_count == 1 && lifo_at(sb, 0) > val)
			return (rot_b() && push_b());
		return (push_b());
	}
	highest = (get_max(sb) < val);
	lowest = !highest && (get_min(sb) > val);
	if (!highest && !lowest)
	{
		while (lifo_at(sb, 0) > val || sb->data[0] < val)
			if (!rot_b())
				return (FALSE);
		return (push_b());
	}
	if (highest)
		mark = get_max(sb);
	else
		mark = get_min(sb);
	while (lifo_at(sb, 0) != mark)
		if (!rot_b())
			return (FALSE);
	return (push_b());
}

t_bool	handle_chunk(t_lifo_stack *sa, t_lifo_stack *sb, size_t chunk, size_t size)
{
	const int	min = chunk * size;
	const int	max = (chunk + 1) * size;
	int			i;

	i = min;
	while (i < max && i < (int)(rt_ptr()->stack_a.elem_count))
	{
		while (lifo_at(sa, 0) < min || lifo_at(sa, 0) >= max)
			if (!rot_a())
				return (FALSE);
		if (!pushval(sa, sb))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

t_bool	chunk_sort(t_runtime *rt)
{
	t_lifo_stack	*s[2];
	size_t			curr;
	size_t			total;
	size_t			chunk_size;

	s[0] = &(rt->stack_a);
	s[1] = &(rt->stack_b);
	curr = 0;
	chunk_size = (s[0]->elem_count / 5) + !!(s[0]->elem_count % 5);
	total = (s[0]->elem_count / chunk_size) + !!(s[0]->elem_count % chunk_size);
	while (curr < total)
	{
		if (!handle_chunk(s[0], s[1], curr, chunk_size))
			return (FALSE);
		++curr;
	}
	int biggest = get_max(s[1]);
	while (lifo_at(s[1], 0) != biggest)
	{
		if (!rot_b())
		{
			return (FALSE);
		}
	}
	while (s[1]->elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}