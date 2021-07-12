#include <chunk_sort.h>

#include <limits.h>

enum e_dir	cs_nearest(t_lifo_stack *s, int max)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = s->elem_count - 1;
	while (i < j)
	{
		if (s->data[i] < max)
			return (DIR_REVERSE);
		if (s->data[j] < max)
			return (DIR_ROTATE);
		++i;
		--j;
	}
	if (i < s->elem_count && s->data[i] < max)
		return (DIR_ROTATE);
	return (DIR_NOT_FOUND);
}

int	cs_get_min(t_lifo_stack *s)
{
	size_t	i;
	int		curr_min;
	int		tmp;

	i = 0;
	curr_min = INT_MAX;
	while (i < s->elem_count)
	{
		tmp = s->data[i];
		if (tmp < curr_min)
			curr_min = tmp;
		++i;
	}
	return (curr_min);
}

int	cs_get_max(t_lifo_stack *s)
{
	size_t	i;
	int		curr_max;
	int		tmp;

	i = 0;
	curr_max = INT_MIN;
	while (i < s->elem_count)
	{
		tmp = s->data[i];
		if (tmp > curr_max)
			curr_max = tmp;
		++i;
	}
	return (curr_max);
}
