#include <ps_runtime.h>
#include <ops.h>
#include <ft_stdbool.h>
#include <checks.h>

typedef enum e_dir
{
	ROTATE,
	REVERSE
}	t_dir;

#include <stdio.h>
static t_dir	nearest_next_min(t_lifo_stack *sa, int *min, int max)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = sa->elem_count - 1;
	while (i < j)
	{
		if (lifo_at(sa, i) < max)
			break ;
		if (lifo_at(sa, j) < max)
			break ;
		++i;
		--j;
	}
	if (lifo_at(sa, i) >= max && lifo_at(sa, j) >= max)
		printf("WAIT THAT'S BAD\n");
	if (lifo_at(sa, i) < max)
	{
		if (min != NULL)
			*min = lifo_at(sa, i);
		return (ROTATE);
	}
	if (min != NULL)
		*min = lifo_at(sa, j);
	return (REVERSE);
}

static void	duo_sort(t_lifo_stack *s, t_bool reverse)
{
	if (!reverse)
	{
		if (lifo_at(s, 0) > lifo_at(s, 1))
			swap_x(s);
	}
	else
	{
		if (lifo_at(s, 0) < lifo_at(s, 1))
			swap_x(s);
	}
}

static void	tri_sort(t_runtime *rt, t_lifo_stack *sa)
{
	int		v[3];

	v[(sa->data[0] > sa->data[1]) + (sa->data[0] > sa->data[2])] = sa->data[0];
	v[(sa->data[1] > sa->data[0]) + (sa->data[1] > sa->data[2])] = sa->data[1];
	v[(sa->data[2] > sa->data[0]) + (sa->data[2] > sa->data[1])] = sa->data[2];
	while (!check_is_sorted(rt))
	{
		if (lifo_at(sa, 0) == v[2])
			rot_a();
		else if (lifo_at(sa, 2) == v[0] || lifo_at(sa, 2) == v[1])
			rrot_a();
		if (lifo_at(sa, 0) == v[1] && lifo_at(sa, 1) == v[0])
			swap_a();
	}
}

// Little reminder: WE DO NOT NEED TO FUCKING CHECK THE OPS RETURN
// arraylist preallocate 16 elems, we won't reach more than 8 ops, so...

static void	large_sort(t_runtime *rt, t_lifo_stack *sa, t_lifo_stack *sb)
{
	size_t	i;
	size_t	to;
	t_dir	dir;
	int		min;

	i = 0;
	to = sa->elem_count - 3;
	while (i < to)
	{
		dir = nearest_next_min(sa, &min, to);
		while (lifo_at(sa, 0) != min)
			if (dir == ROTATE)
				rot_a();
			else
				rrot_a();
		push_b();
		i++;
	}
	if (to != 1)
		duo_sort(sb, TRUE);
	tri_sort(rt, sa);
	while (i--)
		push_a();
}

void	lazy_sort(t_runtime *rt)
{
	t_lifo_stack	*sa;
	t_lifo_stack	*sb;

	rt = rt_ptr();
	sa = &(rt->stack_a);
	sb = &(rt->stack_b);
	if (sa->elem_count == 2)
		duo_sort(sa, FALSE);
	else if (sa->elem_count == 3)
		tri_sort(rt, sa);
	else
		large_sort(rt, sa, sb);
}
