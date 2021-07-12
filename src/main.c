#include <lifo_stack.h>

#include <ps_runtime.h>
#include <sort.h>
#include <array.h>
#include <ft_string.h>
#include <ovm.h>

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
		write(STDOUT_FILENO, "rra\n", 4);
	else if (op == REV_ROT_B)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (op == REV_ROT_AB)
		write(STDOUT_FILENO, "rrr\n", 4);

}

static t_bool	indexify()
{
	t_lifo_stack	*sa;
	size_t			i;
	size_t			j;
	int				below;
	t_aref			tmp;

	sa = &(rt_ptr()->stack_a);
	tmp = anew(sa->elem_count);
	if (!avalid(tmp))
		return (FALSE);
	i = 0;
	while (i < sa->elem_count)
	{
		j = 0;
		below = 0;
		while (j < sa->elem_count)
		{
			if (sa->data[j] < sa->data[i])
				++below;
			++j;
		}
		aput(tmp, i, below);
		++i;
	}
	ft_memcpy(sa->data, tmp.ptr, alen(tmp) * sizeof(int));
	afree(tmp);
	return (TRUE);
}

t_bool	is_sorted(t_runtime *rt)
{
	t_lifo_stack	*sa;
	size_t			i;

	i = 1;
	sa = &(rt->stack_a);
	while (i < sa->elem_count)
	{
		if (sa->data[i - 1] <= sa->data[i])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	enum e_rtinit_ret	ret;

	ret = rt_init_args(argc, argv);
	if (ret == RTINIT_NOARG)
		return (0);
	if (ret != RTINIT_OK)
	{
		write(STDERR_FILENO, "Error\n", 6);
		rt_exit(1);
	}
	if (!indexify())
	{
		write(STDERR_FILENO, "Error\n", 6);
		rt_exit(2);
	}
	if (is_sorted(rt_ptr()))
		rt_exit(0);
	if (!chunk_sort(rt_ptr()))
		rt_exit(3);
	if (!ovm_optimize())
		return (FALSE);
	for (size_t i = 0; i < rt_ptr()->ops.elemcount; ++i)
		print_op(((enum e_ops *)(rt_ptr()->ops.data))[i]);
	rt_exit(0);
}
