#include <checks.h>

t_bool	check_are_sorted(t_runtime *rt)
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

t_bool	check_are_uniques(t_runtime *rt)
{
	t_lifo_stack	*sa;
	size_t			i;
	size_t			j;

	sa = &(rt->stack_a);
	i = 0;
	while (i < (sa->elem_count - 1))
	{
		j = i + 1;
		while (j < sa->elem_count)
		{
			if (sa->data[i] == sa->data[j])
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}
