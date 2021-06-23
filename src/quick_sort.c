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

static t_bool	_qs(t_runtime *rt, size_t n, t_bool preserve);

#include <stdio.h>
static size_t	below_count(t_lifo_stack *s, int pivot, size_t n)
{
	size_t	count;

	count = 0;
	while (n--)
		if (lifo_at(s, n) < pivot)
			++count;
	return (count);
}

static t_bool	transfert_b(t_lifo_stack *s, int pivot, size_t n, size_t *count)
{
	size_t	backlog;
	size_t	i;
	size_t	_count;

	backlog = 0;
	i = 0;
	_count = 0;
	while (i++ < n)
	{
		if (lifo_at(s, 0) < pivot)
		{
			++backlog;
			if (!rot_x(s))
				return (FALSE);
			continue ;
		}
		if (!push_nx(s))
			return (FALSE);
		++_count;
	}
	while (backlog--)
		if (!rrot_x(s))
			return (FALSE);
	if (count)
		*count = _count;
	return (TRUE);
}

static t_bool	_qs_b(t_runtime *rt, size_t n)
{
	t_lifo_stack	*sb;
	int				pivot;
	size_t			ntrans;
	size_t			below;

	sb = &(rt->stack_b);
	below = below_count(sb, pivot, n);
	if (n <= 2)
	{
		if (n == 2)
			if (lifo_at(sb, 0) >= lifo_at(sb, 1))
				if (!swap_b())
					return (FALSE);
		while (n--)
			if (!push_b())
				return (FALSE);
		return (TRUE);
	}
	if (!median(sb->data + (sb->elem_count - n), n, n / 2, &pivot))
		return (TRUE);
	if (!transfert_b(sb, pivot, n, &ntrans))
		return (FALSE);
	if (!_qs(rt, ntrans, TRUE))
		return (FALSE);
	if (!_qs_b(rt, n - ntrans))
		return (FALSE);
	return (TRUE);
}

static enum e_dir	nearest(t_lifo_stack *s, int pivot, size_t n)
{
	size_t			i;
	size_t			j;

	i = s->elem_count - n;
	// printf("elem_count: %zu\n", s->elem_count);
	// printf("n:          %zu\n", n);
	// printf("i:          %zu\n", i);
	j = s->elem_count - 1;
	if (s->elem_count == 0)
		return (DIR_NOT_FOUND);
	while (i < j)
	{
		if (s->data[i] < pivot)
			return (DIR_REVERSE);
		if (s->data[j] < pivot)
			return (DIR_ROTATE);
		++i;
		--j;
	}
	if (s->data[i] < pivot)
		return (DIR_ROTATE);
	return (DIR_NOT_FOUND);
}

static t_bool	ptransfert(t_lifo_stack *s, int pivot, size_t n, size_t *count)
{
	size_t	backlog;
	size_t	i;
	size_t	_count;

	backlog = 0;
	i = 0;
	_count = 0;
	while (i++ < n)
	{
		if (lifo_at(s, 0) >= pivot)
		{
			++backlog;
			if (!rot_x(s))
				return (FALSE);
			continue ;
		}
		if (!push_nx(s))
			return (FALSE);
		++_count;
	}
	while (backlog--)
		if (!rrot_x(s))
			return (FALSE);
	if (count)
		*count = _count;
	return (TRUE);
}

static t_bool	transfert(t_lifo_stack *s, int pivot, size_t n, size_t *count)
{
	enum e_dir	dir;
	t_bool		ret;
	size_t		_count;

	_count = 0;
	while (1)
	{
		dir = nearest(s, pivot, n - _count);
		if (dir == DIR_NOT_FOUND)
			break ;
		while (lifo_at(s, 0) >= pivot)
		{
			if (dir == DIR_ROTATE)
				ret = rot_x(s);
			else
				ret = rrot_x(s);
			if (!ret)
				return (FALSE);
		}
		if (!push_nx(s))
			return (FALSE);
		++_count;
	}
	if (count != NULL)
		*count = _count;
	return (TRUE);
}

// FIXME: quick_sort.c::_qs handle group <= 3

static t_bool	_qs(t_runtime *rt, size_t n, t_bool preserve)
{
	t_lifo_stack	*sa;
	int				pivot;
	size_t			ntrans;

	sa = &(rt->stack_a);
	if (n <= 2)
	{
		if (n == 2 && lifo_at(sa, 0) < lifo_at(sa, 1))
			if (!swap_a())
				return (FALSE);
		return (_qs_b(rt, (n % 2) + 1));
	}
	if (!median(sa->data + (sa->elem_count - n), n, n / 2, &pivot))
		return (FALSE);
	if (preserve && !ptransfert(sa, pivot, n, &ntrans))
		return (FALSE);
	else if (!preserve && !transfert(sa, pivot, n, &ntrans))
		return (FALSE);
	if (!_qs(rt, n - ntrans, preserve))
		return (FALSE);
	return (_qs_b(rt, ntrans));
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
	if (!_qs(rt, rt->stack_a.elem_count, FALSE))
		return (FALSE);
	if (!_qs_b(rt, rt->stack_b.elem_count))
		return (FALSE);
	return (TRUE);
}
