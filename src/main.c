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
		return (1);
	}
	for (int i = argc - 2; i >= 0; --i) {
		printf("[%d]: %d\n", argc - 2 - i, rt_ptr()->stack_a.data[i]);
	}
	sort();
	rt_exit(0);
}
