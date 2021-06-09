0#include <ps_runtime.h>

#include <array.h>
#include <median.h>
#include <ops.h>

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
		}
	}
	return (below);
}

static t_bool	pushvals(t_runtime *rt, int v0, int v1, int nmax)
{
	size_t	n;
	int		v;

	n = 0;
	while (n < nmax)
	{
		v = rt->stack_a.data[rt->stack_a.elem_count - 1];
		if (v == v0 || v == v1)
		{
			if (!push_b())
				return (FALSE);
			++n;
		}
	}
	return (TRUE);
}

static t_bool	handle_atomic(t_runtime *rt, t_aref below)
{
	if (below.length <= 1)
		return (pushvals(rt, below.ptr[0], below.ptr[0], 1));
	if (rt->stack_b.data[0] < rt->stack_b.data[1])
		if (!swap_b())
			return (FALSE);
		pushvals(rt, below.ptr[0], below.ptr[1], 2);
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
	int	pivot;

	if (!median(rt->stack_a.data, rt->stack_a.elem_count, rt->stack_a.elem_count, &pivot))
		return (FALSE);
	return (_qs(rt, pivot));
}
