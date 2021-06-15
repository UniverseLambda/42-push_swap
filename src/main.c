#include <lifo_stack.h>

#include <ps_runtime.h>
#include <sort.h>

#include <unistd.h>

#include <stdio.h>
int	main(int argc, char *argv[])
{
	enum e_rtinit_ret	ret;
	
	ret = rt_init_args(argc, argv);
	if (ret == RTINIT_NOARG)
		return (0);
	if (ret != RTINIT_OK)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (2);
	}
	for (int i = argc - 2; i >= 0; --i) {
		printf("[%d]: %d\n", argc - 2 - i, rt_ptr()->stack_a.data[i]);
	}
	// sort();
	quick_sort(rt_ptr());
	puts("STACK A");
	for (int i = rt_ptr()->stack_a.elem_count - 1; i >= 0; --i) {
		printf("[%zu]: %d\n", rt_ptr()->stack_a.elem_count - 1 - i, rt_ptr()->stack_a.data[i]);
	}
	puts("STACK B");
	for (int i = rt_ptr()->stack_b.elem_count - 1; i >= 0; --i) {
		printf("[%zu]: %d\n", rt_ptr()->stack_b.elem_count - 1 - i, rt_ptr()->stack_b.data[i]);
	}
	// rt_exit(!quick_sort(rt_ptr()));
	rt_exit(0);
}
