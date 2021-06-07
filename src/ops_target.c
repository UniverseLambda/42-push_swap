#include <ops.h>

#include <lifo_stack.h>
#include <ps_runtime.h>

int	swap_x(t_lifo_stack *stack)
{
	const t_runtime *rt = rt_ptr();

	if (stack == &(rt->stack_a))
		return (swap_a());
	return (swap_b());
}

int	push_x(t_lifo_stack *stack)
{
	const t_runtime *rt = rt_ptr();

	if (stack == &(rt->stack_a))
		return (push_a());
	return (push_b());
}

int	rot_x(t_lifo_stack *stack)
{
	const t_runtime *rt = rt_ptr();

	if (stack == &(rt->stack_a))
		return (rot_a());
	return (rot_b());
}

int	rrot_x(t_lifo_stack *stack)
{
	const t_runtime *rt = rt_ptr();

	if (stack == &(rt->stack_a))
		return (rrot_a());
	return (rrot_b());
}
