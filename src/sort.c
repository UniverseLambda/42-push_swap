#include <sort.h>
#include <ps_runtime.h>
#include <median.h>

#include <stdio.h>
void	sort()
{
	t_runtime	*rt;
	int			m;

	rt = rt_ptr();
	median(rt->stack_a.data, rt->stack_a.elem_count, &m);
	printf("Median: %d\n", m);
}
