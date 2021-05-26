#include <ops.h>

#include <ps_runtime.h>
#include <lifo_stack.h>

int	swap_a(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_swap(&(rt->stack_a));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = SWAP_A;
	return (1);
}

int	swap_b(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_swap(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = SWAP_B;
	return (1);
}

int	swap_ab(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_swap(&(rt->stack_a));
	lifo_swap(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = SWAP_AB;
	return (1);
}

int	push_a(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_push(&(rt->stack_a), &(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = PUSH_A;
	return (1);
}

int	push_b(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_push(&(rt->stack_b), &(rt->stack_a));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = PUSH_B;
	return (1);
}
