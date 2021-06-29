#include <ovm.h>

#include <ps_runtime.h>

static void	pack_ops(t_runtime *rt)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	while (i < rt->ops.elemcount)
	{
		if (*(op_ptr(i)) == NOOP)
		{
			n = 0;
			while ((i + n) < rt->ops.elemcount && *(op_ptr(i + n)) == NOOP)
				++n;
			if (i + n >= rt->ops.elemcount)
				break ;
			j = 0;
			while ((i + n + j) < rt->ops.elemcount)
			{
				op_ptr(i)[j] = op_ptr(i + n)[j];
				op_ptr(i + n)[j] = NOOP;
				++j;
			}
		}
		++i;
	}
}

void	readjust_rotates()
{
	t_ovm	vm;
	size_t	n;
	size_t	i;

	vm = init_ovm();
	while (vm.rip < vm.ops->elemcount)
	{
		vm = ovm_until_op(vm, ROT_B);
		n = 0;
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

void	remove_useless()
{
	t_ovm		current;
	size_t		ra;
	size_t		rb;
	size_t		i;
	enum e_ops	op;

	ra = 0;
	rb = 0;
	current = init_ovm();
	while (current.rip < current.ops->elemcount)
	{
		op = *(op_ptr(current.rip));
		ra = (ra * !(op != ROT_A && op != ROT_B && op != NOOP)) + (op == ROT_A);
		rb = (rb * !(op != ROT_A && op != ROT_B && op != NOOP)) + (op == ROT_B);
		if (ra >= current.sa.elem_count)
		{
			i = -1;
			while (++i < current.sa.elem_count && (ra--))
				op_ptr(current.rip - ra)[i] = NOOP;
			ra -= current.sa.elem_count;
		}
		if (rb >= current.sb.elem_count)
		{
			i = -1;
			while (++i < current.sb.elem_count && (rb--))
				op_ptr(current.rip - rb)[i] = NOOP;
		}
		ovm_next(&current);
	}
}

t_bool	ovm_optimize()
{
	t_runtime	*rt;

	rt = rt_ptr();
	remove_useless();
	pack_ops(rt);
	readjust_rotates();
	pack_ops(rt);
	return (TRUE);
}
