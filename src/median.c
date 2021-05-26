#include <median.h>

#include <ft_string.h>
#include <ft_stdlib.h>
#include <ft_norm.h>
#include <stdlib.h>

#include <stdio.h>
static void swap_val(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void median_sort(int *sorted, size_t count)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		index = i;
		while (j < count)
		{
			if (sorted[index] < sorted[j])
				index = j;
			++j;
		}
		swap_val(sorted + i, sorted + index);
		++i;
	}
}

static int	median_sorted(int *values, size_t count)
{
	int		sorted[5];
	
	ft_memcpy(sorted, values, count * sizeof(*values));
	median_sort(sorted, count);
	puts("-- SORTED --");
	for (size_t i = 0; i < count; ++i)
	{
		printf("(%zu): %d\n", i, sorted[i]);
	}
	if ((count % 2) == 0)
	{
		printf("local_median: %d\n", sorted[count / 2 - 1]);
		return (sorted[count / 2 - 1]);
	}
	printf("local_median: %d\n", sorted[count / 2]);
	return (sorted[count / 2]);
}

static int	find_pivot(int *values, size_t count, int *ret)
{
	size_t	i;
	size_t	max_group;
	int		*medians;
	int		result;

	puts("====== FIND PIVOT ======");
	i = 0;
	max_group = (count / 5) + !!(count % 5);
	if (max_group == 1)
	{
		*ret = median_sorted(values, count);
		return (1);
	}
	if (set_ptr(&medians, ft_calloc(sizeof(int), max_group)) == NULL)
		return (0);
	while (i < max_group)
	{
		if (i < max_group - 1 || (count % 5) == 0)
			medians[i] = median_sorted(values + (i * 5), 5);
		else
			medians[i] = median_sorted(values + (i * 5), count % 5);
		++i;
	}
	result = find_pivot(medians, max_group, ret);
	free(medians);
	return (result);
}

int	median(int *values, size_t count, int *ret)
{
	int	pivot;

	if (!find_pivot(values, count, &pivot))
		return (0);
	printf("PIVOT: %d\n", pivot);
	return (median_from_pivot(values, count, pivot, ret));
}
