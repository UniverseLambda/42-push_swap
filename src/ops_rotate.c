#include <ops.h>

#include <ps_runtime.h>
#include <lifo_stack.h>

int	rot_a(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_rotate(&(rt->stack_a));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = ROT_A;
	return (1);
}

int	rot_b(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_rotate(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = ROT_B;
	return (1);
}

int	rot_ab(void)
{
	t_runtime	*rt;
	enum e_ops	*op;

	rt = rt_ptr();
	lifo_rotate(&(rt->stack_a));
	lifo_rotate(&(rt->stack_b));
	op = arraylist_newelem(&(rt->ops));
	if (op == NULL)
		return (0);
	*op = ROT_AB;
	return (1);
}
