#include <sort.h>
#include <ps_runtime.h>
#include <median.h>

#include <ft_stdbool.h>

#include <stdio.h>
static void	spread(t_runtime *rt, int pivot)
{
	size_t		i;
	size_t		max_move;
	int			val;

	i = 0;
	max_move = rt->stack_a.elem_count;
	while (i < max_move)
	{
		val = lifo_head(&(rt->stack_a));
		if (val < pivot)
			push_b();
		else
			rot_a();
		++i;
	}

	puts("STACK A STATE");
	for (size_t j = rt->stack_a.elem_count; j > 0; --j) {
		printf("[%zu]: %d\n", rt->stack_a.elem_count - j, rt_ptr()->stack_a.data[j - 1]);
	}

	puts("STACK B STATE");
	for (size_t j = rt->stack_b.elem_count; j > 0; --j) {
		printf("[%zu]: %d\n", rt->stack_b.elem_count - j, rt_ptr()->stack_b.data[j - 1]);
	}
}

static t_bool	is_sorted(t_lifo_stack *stack)
{
	size_t	i;

	i = 1;
	while (i < stack->elem_count)
	{
		if (stack->data[i - 1] > stack->data[i])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static void	sort_m(t_runtime *rt)
{
	t_lifo_stack	*a;
	t_lifo_stack	*b;
	t_bool			asorted;
	t_bool			bsorted;

	a = &(rt->stack_a);
	b = &(rt->stack_b);
	while (1)
	{
		asorted = is_sorted(a);
		bsorted = is_sorted(b);
	}
}

void	sort(void)
{
	t_runtime	*rt;
	int			m;

	rt = rt_ptr();
	median(rt->stack_a.data, rt->stack_a.elem_count, rt->stack_a.elem_count / 2, &m);
	printf("Median: %d\n", m);
	spread(rt, m);
	// sort_m(rt);
}
