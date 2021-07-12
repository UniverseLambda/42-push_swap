#include <ovm.h>

typedef struct s_frame
{
	t_ovm		vm;
	size_t		start;
	size_t		count_a;
	size_t		count_b;
	size_t		size;
	enum e_ops	current;
	enum e_ops	expected;
}				t_frame;

void	ovm_apply_merge(size_t start, size_t count_a, size_t count_b,
	enum e_ops replacement)
{
	size_t	i;

	i = 0;
	while (i < count_a + count_b)
	{
		if (i < count_a && i < count_b)
		{
			*op_ptr(start + i) = replacement;
		}
		else
		{
			*op_ptr(start + i) = NOOP;
		}
		++i;
	}
}

static t_bool	next_frame(t_ovm *vm, t_frame *frame)
{
	while (vm->rip < vm->ops->elemcount)
	{
		if (*op_ptr(vm->rip) == ROT_A || *op_ptr(vm->rip) == REV_ROT_A)
		{
			frame->start = vm->rip;
			frame->current = *op_ptr(vm->rip);
			if (*op_ptr(vm->rip) == ROT_A)
				frame->expected = ROT_B;
			else
				frame->expected = REV_ROT_B;
			return (TRUE);
		}
		ovm_next(vm);
	}
	return (FALSE);
}

static t_bool	get_count(t_ovm *vm, t_frame *frame)
{
	frame->size = 0;
	frame->count_a = 0;
	frame->count_b = 0;
	while (vm->rip < vm->ops->elemcount)
	{
		if (*op_ptr(vm->rip) == frame->current)
			frame->count_a += 1;
		else if (*op_ptr(vm->rip) == frame->expected)
			frame->count_b += 1;
		else
			break ;
		frame->size += 1;
		ovm_next(vm);
	}
	if ((frame->count_a == 0 || frame->count_b == 0)
		&& vm->rip >= vm->ops->elemcount)
		return (FALSE);
	return (TRUE);
}

static void	apply_merge(t_frame *frame)
{
	size_t	i;
	size_t	noop_count;

	i = 0;
	noop_count = frame->count_a;
	if (frame->count_a > frame->count_b)
		noop_count = frame->count_b;
	while (i < frame->size)
	{
		if (i < frame->count_a && i < frame->count_b)
		{
			op_ptr(frame->start)[i] = REV_ROT_AB;
			if (frame->current == ROT_A)
				op_ptr(frame->start)[i] = ROT_AB;
		}
		else if (i < frame->size - noop_count)
		{
			op_ptr(frame->start)[i] = frame->expected;
			if (frame->count_a > frame->count_b)
				op_ptr(frame->start)[i] = frame->current;
		}
		else
			op_ptr(frame->start)[i] = NOOP;
		++i;
	}
}

void	ovm_merge(void)
{
	t_ovm		vm;
	t_frame		frame;

	vm = init_ovm();
	while (vm.rip < vm.ops->elemcount && *op_ptr(vm.rip) != PUSH_A)
	{
		if (!next_frame(&vm, &frame))
			return ;
		if (!get_count(&vm, &frame))
			return ;
		apply_merge(&frame);
	}
}
