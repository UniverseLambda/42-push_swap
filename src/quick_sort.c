#include <ps_runtime.h>

#include <array.h>
#include <median.h>
#include <ops.h>
#include <limits.h>

static t_aref	abelow(t_runtime *rt, int pivot)
{
	t_aref	below;
	size_t	i;
	size_t	aidx;
	size_t	n;

	i = 0;
	n = 0;
	while (i < rt->stack_a.elem_count)
	{
		if (rt->stack_a.data[i] < pivot)
			++n;
		++i;
	}
	below = anew(n);
	i = 0;
	aidx = 0;
	if (avalid(below))
	{
		while (i < rt->stack_a.elem_count)
		{
			if (rt->stack_a.data[i] < pivot)
				aput(below, aidx++, rt->stack_a.data[i]);
			++i;
		}
	}
	return (below);
}

static int		determine_direction(t_runtime *rt, int v0, int v1)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = rt->stack_a.elem_count - 1;
	while (i < j)
	{
		if (rt->stack_a.data[i] == v0 || rt->stack_a.data[i] == v1)
			return (0);
		if (rt->stack_a.data[j] == v0 || rt->stack_a.data[j] == v1)
			return (1);
		++i;
		--j;
	}
	return (0);
}

static t_bool	pushvals(t_runtime *rt, int v0, int v1, int nmax)
{
	int		n;
	int		v;
	int		dir;

	n = 0;
	dir = determine_direction(rt, v0, v1);
	while (n < nmax)
	{
		v = rt->stack_a.data[rt->stack_a.elem_count - 1];
		if (v == v0 || v == v1)
		{
			if (!push_b())
				return (FALSE);
			determine_direction(rt, v0, v1);
			++n;
		}
		else
		{
			if (dir == 0)
			{
				if (!rrot_a())
					return (FALSE);
			}
			else
				if (!rot_a())
					return (FALSE);
		}
	}
	return (TRUE);
}

static t_bool	handle_atomic(t_runtime *rt, t_aref below)
{
	if (below.length <= 1)
		return (pushvals(rt, below.ptr[0], below.ptr[0], 1));
	if (!pushvals(rt, below.ptr[0], below.ptr[1], 2))
		return (FALSE);
	if (rt->stack_b.data[rt->stack_b.elem_count - 1] < rt->stack_b.data[rt->stack_b.elem_count - 2])
		if (!swap_b())
			return (FALSE);
	return (TRUE);
}

static t_bool	_qs(t_runtime *rt, int pivot)
{
	t_lifo_stack	*stack_a;
	t_aref			below;
	int				next_pivot;
	t_bool			ret;

	stack_a = &(rt->stack_a);
	below = abelow(rt, pivot);
	if (!avalid(below))
		return (FALSE);
	if (below.length <= 2)
	{
		ret = handle_atomic(rt, below);
		afree(below);
		return (ret);
	}
	ret = FALSE;
	if (median(below.ptr, below.length, below.length / 2, &next_pivot))
	{
		ret = _qs(rt, next_pivot);
		if (ret)
			ret = _qs(rt, pivot);
	}
	afree(below);
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
	if (!_qs(rt, max))
		return (FALSE);
	while (rt->stack_b.elem_count > 0)
		if (!push_a())
			return (FALSE);
	return (TRUE);
}
