#include <ps_runtime.h>

#include <array.h>
#include <median.h>
#include <ops.h>
#include <limits.h>

enum	e_dir
{
	DIR_NOT_FOUND,
	DIR_ROTATE,
	DIR_REVERSE
};

// min: inclusive; max: exclusive
// Special case: when min == max, it will find the shortest way to min

static enum e_dir	nearest(t_lifo_stack *s, t_aref below)
{
	size_t			i;
	size_t			j;
	size_t			k;

	i = 0;
	j = s->elem_count - 1;
	if (!alen(below))
		return (DIR_NOT_FOUND);
	while (i < j || (alen(below) > 2 || i <= j))
	{
		k = 0;
		while (k < alen(below))
		{
			if (s->data[i] == aget(below, k))
				return (DIR_REVERSE);
			if (s->data[j] == aget(below, k))
				return (DIR_ROTATE);
			++k;
		}
		++i;
		--j;
	}
	return (DIR_NOT_FOUND);
}

static t_bool	handle_atomic(t_runtime *rt, t_aref below)
{
	enum e_dir	dir;
	size_t		k;
	size_t		it;
	t_bool		found;
	t_bool		ret;

	it = 0;
	while  (it++ < alen(below))
	{
		found = FALSE;
		dir = nearest(&(rt->stack_a), below);
		while (!found)
		{
			k = 0;
			while (k < alen(below))
			{
				if (lifo_at(&(rt->stack_a), 0) == aget(below, k))
				{
					found = TRUE;
					break;
				}
				++k;
			}
			if (!found)
			{
				if (dir == DIR_ROTATE)
					ret = rot_a();
				else
					ret = rrot_a();
				if (!ret)
					return (FALSE);
			}
		}
		if (!push_b())
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	_qs(t_runtime *rt)
{
	t_lifo_stack	*sa;
	int				next_pivot;
	t_bool			ret;
	enum e_dir		dir;

	sa = &(rt->stack_a);
	ret = FALSE;
	if (!median(sa->data, sa->elem_count, sa->elem_count / 2, &next_pivot))
		return (FALSE);
	
	return (ret);
}

t_bool	quick_sort(t_runtime *rt)
{
	size_t	i;
	int		max;
	
	i = 0;
	max = INT_MIN;
	while (i < rt->stack_a.elem_count)
	{
		if (max < rt->stack_a.data[i])
			max = rt->stack_a.data[i];
		++i;
	}
	if (!_qs(rt))
		return (FALSE);
	while (rt->stack_b.elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}
