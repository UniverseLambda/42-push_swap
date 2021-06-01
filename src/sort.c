#include <sort.h>
#include <ps_runtime.h>
#include <median.h>

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

void	sort()
{
	t_runtime	*rt;
	int			m;

	rt = rt_ptr();
	median(rt->stack_a.data, rt->stack_a.elem_count, rt->stack_a.elem_count / 2, &m);
	printf("Median: %d\n", m);
	spread(rt, m);
}
