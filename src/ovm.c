#include <ovm.h>

#include <ps_runtime.h>

void	ovm_next(t_ovm *ovm)
{
	enum e_ops	op;

	if (ovm->rip >= ovm->ops->elemcount)
		return ;
	op = *(op_ptr(ovm->rip));
	if (op == PUSH_A)
	{
		ovm->sb.elem_count -= (ovm->sb.elem_count != 0);
		ovm->sa.elem_count += (ovm->sb.elem_count != 0);
	}
	else if (op == PUSH_B)
	{
		ovm->sa.elem_count -= (ovm->sa.elem_count != 0);
		ovm->sb.elem_count += (ovm->sa.elem_count != 0);
	}
	++(ovm->rip);
}

t_ovm	ovm_until_index(t_ovm ovm, size_t opidx)
{
	while (ovm.rip < opidx && ovm.rip < ovm.ops->elemcount)
		ovm_next(&ovm);
	return (ovm);
}

t_ovm	ovm_until_op(t_ovm ovm, enum e_ops op)
{
	while (ovm.rip < ovm.ops->elemcount && *(op_ptr(ovm.rip)) != op)
		ovm_next(&ovm);
	return (ovm);
}

t_ovm	ovm_until_nop(t_ovm ovm, enum e_ops op)
{
	while (ovm.rip < ovm.ops->elemcount && *(op_ptr(ovm.rip)) == op)
		ovm_next(&ovm);
	return (ovm);
}

t_ovm	init_ovm()
{
	t_runtime	*rt;
	t_ovm		ovm;

	rt = rt_ptr();
	ovm.rip = 0;
	ovm.ops = &(rt->ops);
	ovm.sa.elem_count = rt->stack_a.stack_size;
	ovm.sb.elem_count = 0;
	return (ovm);
}
