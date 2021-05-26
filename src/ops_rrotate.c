#include <ops.h>

#include <ps_runtime.h>
#include <lifo_stack.h>

int	rrot_a(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_reverse_rotate(&(rt->stack_a));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = REV_ROT_A;
	return (1);
}

int	rrot_b(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_reverse_rotate(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = REV_ROT_B;
	return (1);
}

int	rrot_ab(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_reverse_rotate(&(rt->stack_a));
	lifo_reverse_rotate(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = REV_ROT_AB;
	return (1);
}
