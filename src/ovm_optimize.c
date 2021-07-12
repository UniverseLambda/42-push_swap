#include <ovm.h>

#include <ps_runtime.h>

static void	pack_ops(t_runtime *rt)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < rt->ops.elemcount)
	{
		if (*op_ptr(i) == NOOP)
		{
			j = i;
			while (j < rt->ops.elemcount && *op_ptr(j) == NOOP)
				++j;
			k = 0;
			while ((k + j) < rt->ops.elemcount)
			{
				op_ptr(i)[k] = op_ptr(j)[k];
				op_ptr(j)[k] = NOOP;
				++k;
			}
		}
		++i;
	}
}

void	readjust_rotates(void)
{
	t_ovm	vm;
	size_t	n;
	size_t	i;

	vm = init_ovm();
	while (vm.rip < vm.ops->elemcount)
	{
		vm = ovm_until_op(vm, ROT_B);
		n = 1;
		while (vm.rip + n < vm.ops->elemcount && op_ptr(vm.rip)[n] == ROT_B)
			++n;
		if (n > vm.sb.elem_count - n)
		{
			i = 0;
			while (i < n)
			{
				if (i < vm.sb.elem_count - n)
					op_ptr(vm.rip)[i] = REV_ROT_B;
				else
					op_ptr(vm.rip)[i] = NOOP;
				++i;
			}
		}
		vm = ovm_until_nop(vm, ROT_B);
	}
}

t_bool	ovm_optimize(void)
{
	t_runtime	*rt;

	rt = rt_ptr();
	readjust_rotates();
	pack_ops(rt);
	ovm_merge();
	return (TRUE);
}
