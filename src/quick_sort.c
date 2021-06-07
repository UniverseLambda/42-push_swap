#include <ps_runtime.h>

#include <array.h>
#include <median.h>

static t_bool	_putb(int v0, int v1)
{
	
}

static t_bool	_qs(t_runtime *rt, t_aref a)
{
	int		med;

	if (a.length <= 1)
		return (TRUE);
	if (a.length == 2)
		return (_putb(aget(a, 0), aget(a, 1)));
	if (!median(a.ptr, a.length, a.length / 2, &med))
		return (FALSE);
}

t_bool	quick_sort(t_runtime *rt)
{
	if (!_qs(rt, awrap(rt->stack_a.data, rt->stack_a.elem_count)))
		return (FALSE);
	return (TRUE);
}
