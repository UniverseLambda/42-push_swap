#include <median.h>

#include <ft_stdlib.h>
#include <stdlib.h>

static int	*reorder(int *values, size_t count, int pivot, size_t *pivot_index)
{
	int		*array;
	size_t	i;
	size_t	j_start;
	size_t	j_end;

	array = ft_calloc(count, sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	j_start = 0;
	j_end = count - 1;
	while (i < count)
	{
		if (values[i] == pivot && pivot_index != NULL)
			*pivot_index = j_start;
		if (values[i] <= pivot)
			array[j_start++] = values[i];
		else
			array[j_end--] = values[i];
		++i;
	}
	return (array);
}

int	median_from_pivot(int *values, size_t count, int pivot, int *ret)
{
	size_t	pivot_index;
	int		*sorted;
	int		retv;

	sorted = reorder(values, count, pivot, &pivot_index);
	if (sorted == NULL)
		return (0);
	retv = 1;
	if (pivot_index == count / 2) 
		*ret = values[pivot_index];
	else if (count / 2 < pivot_index)
		retv = median(sorted, pivot_index - 1, ret);
	else
		retv = median(sorted + pivot_index + 1, count - pivot_index, ret);
	free(sorted);
	return (retv);
}
