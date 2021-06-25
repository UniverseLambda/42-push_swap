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

static size_t	above_count(t_lifo_stack *s, int pivot, size_t n)
{
	size_t	count;

	count = 0;
	while (n--)
	if (lifo_at(s, n) >= pivot)
			++count;
	return (count);
}

#include <stdio.h>
static t_bool	_median_b(t_lifo_stack *s, int pivot, size_t n, int *result)
{
	size_t	count;
	t_aref	above;
	size_t	i;
	size_t	j;
	int		ret;

	i = n;
	count = above_count(s, pivot, n);
	if (count == 0)
	{
		puts("!");
		return (TRUE);
	}
	above = anew(count);
	if (!avalid(above))
	{
		puts("@");
		return (FALSE);
	}
	i = n;
	j = 0;
	while (i--)
		if (lifo_at(s, i) >= pivot)
			if (!aput(above, j++, lifo_at(s, i)))
			{
				puts("#");
				afree(above);
				return (FALSE);
			}
	ret = median(above.ptr, above.length, (above.length / 2), result);
	afree(above);
	return (ret);
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

static t_bool	_qs_b(t_runtime *rt, size_t n, int pivot)
{
	t_lifo_stack	*sb;
	size_t			count;
	size_t			ntrans;
	int				next_pivot;

	sb = &(rt->stack_b);
	if (n <= 2)
	{
		if (n == 2)
			if (lifo_at(sb, 0) >= lifo_at(sb, 1))
				if (!swap_b())
				{
					puts("A");
					return (FALSE);
				}
		while (n--)
			if (!push_b())
			{
				puts("B");
				return (FALSE);
			}
		return (TRUE);
	}
	if (!_median_b(sb, pivot, n, &next_pivot))
	{
		puts("C");
		return (FALSE);
	}
	count = above_count(sb, next_pivot, n);
	if (count <= 2)
	{
		if (!transfert_b(sb, next_pivot, n, &ntrans))
		{
			puts("D");
			return (FALSE);
		}
		if (ntrans > 1 && lifo_at(&(rt->stack_a), 0) > lifo_at(&(rt->stack_a), 1))
			if (!swap_a())
			{
				puts("E");
				return (FALSE);
			}
		n -= ntrans;
		next_pivot = pivot;
	}
	if (!_qs_b(rt, n, next_pivot))
	{
		puts("F");
		return (FALSE);
	}
	return (TRUE);
}

static enum e_dir	nearest(t_lifo_stack *s, int pivot, size_t n)
{
	size_t			i;
	size_t			j;

	i = s->elem_count - n;
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
	if (!median(sa->data + (sa->elem_count - n), n, n / 2, &pivot))
		return (FALSE);
	if (n <= 2)
	{
		if (n == 2 && lifo_at(sa, 0) < lifo_at(sa, 1))
			if (!swap_a())
			{
				puts("0");
				return (FALSE);
			}
		return (_qs_b(rt, (n % 2) + 1, pivot));
	}
	if (preserve && !ptransfert(sa, pivot, n, &ntrans))
	{
		puts("1");
		return (FALSE);
	}
	else if (!preserve && !transfert(sa, pivot, n, &ntrans))
	{
		puts("2");
		return (FALSE);
	}
	if (!_qs(rt, n - ntrans, preserve))
	{
		puts("3");
		return (FALSE);
	}
	if (!_qs_b(rt, ntrans, pivot))
	{
		puts("4");
		return (FALSE);
	}
	return (TRUE);
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
	return (TRUE);
}
