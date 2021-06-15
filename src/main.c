#include <lifo_stack.h>

#include <ps_runtime.h>
#include <sort.h>

#include <unistd.h>

static void	print_op(enum e_ops op)
{
	if (op == SWAP_A)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (op == SWAP_B)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (op == SWAP_AB)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (op == PUSH_A)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (op == PUSH_B)
		write(STDOUT_FILENO, "pb\n", 3);
	else if (op == ROT_A)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (op == ROT_B)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (op == ROT_AB)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (op == REV_ROT_A)
		write(STDOUT_FILENO, "rra\n", 3);
	else if (op == REV_ROT_B)
		write(STDOUT_FILENO, "rrb\n", 3);
	else if (op == REV_ROT_AB)
		write(STDOUT_FILENO, "rrr\n", 3);
	
}

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
	// for (int i = argc - 2; i >= 0; --i) {
	// 	printf("[%d]: %d\n", argc - 2 - i, rt_ptr()->stack_a.data[i]);
	// }
	// sort();
	if (!quick_sort(rt_ptr()))
		rt_exit(2);
	for (size_t i = 0; i < rt_ptr()->ops.elemcount; ++i)
		print_op(((enum e_ops *)(rt_ptr()->ops.data))[i]);
	rt_exit(0);
}
