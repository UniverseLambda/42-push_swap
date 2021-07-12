#include <chunk_sort.h>

#include <ps_runtime.h>
#include <array.h>
#include <ops.h>

// min: inclusive; max: exclusive

static size_t	get_group_count(size_t total)
{
	if (total >= 400)
		return (15);
	if (total >= 350)
		return (12);
	if (total >= 300)
		return (10);
	if (total >= 200)
		return (8);
	if (total >= 100)
		return (5);
	if (total >= 25)
		return (2);
	return (1);
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
	higlow = (cs_get_max(sb) < val) || (cs_get_min(sb) > val);
	if (!higlow)
	{
		while (lifo_at(sb, 0) > val || sb->data[0] < val)
			if (!rot_b())
				return (FALSE);
		return (push_b());
	}
	mark = cs_get_max(sb);
	while (lifo_at(sb, 0) != mark)
		if (!rot_b())
			return (FALSE);
	return (push_b());
}

static t_bool	handle_chunk(t_lifo_stack *sa, t_lifo_stack *sb, int max)
{
	size_t		it;
	enum e_dir	dir;

	it = 0;
	dir = cs_nearest(sa, max);
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
		dir = cs_nearest(sa, max);
	}
	return (TRUE);
}

t_bool	chunk_sort(t_runtime *rt)
{
	t_lifo_stack	*s[2];
	size_t			curr;
	size_t			total;
	size_t			size_div[2];
	int				biggest;

	s[0] = &(rt->stack_a);
	s[1] = &(rt->stack_b);
	curr = 0;
	total = get_group_count(s[0]->elem_count);
	size_div[0] = (s[0]->elem_count / total);
	size_div[1] = (s[0]->elem_count % total);
	while (curr++ < total)
		if (!handle_chunk(s[0], s[1], (curr * size_div[0]) + size_div[1]))
			return (FALSE);
	biggest = cs_get_max(s[1]);
	while (lifo_at(s[1], 0) != biggest)
		if (!rrot_b())
			return (FALSE);
	while (s[1]->elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}
