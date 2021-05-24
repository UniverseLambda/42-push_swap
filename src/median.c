#include <median.h>

#include <ft_string.h>
#include <ft_stdlib.h>
#include <ft_norm.h>
#include <stdlib.h>

static void sort(int *sorted, size_t count)
{
	size_t	i;
	size_t	j;
	int		index;
	int		tmp;

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
		tmp = sorted[i];
		sorted[i] = sorted[index];
		sorted[index] = tmp;
		++i;
	}
}

static int	median_sorted(int *values, size_t count)
{
	int		sorted[5];
	
	ft_memcpy(sorted, values, count * sizeof(*values));
	sort(sorted, count);
	return (sorted[count / 2]);
}

static int	find_pivot(int *values, size_t count, int *ret)
{
	size_t	i;
	size_t	max_group;
	int		*medians;

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
		if (i < max_group - 1)
			medians[i] = median_sorted(values + (i * 5), 5);
		else
			medians[i] = median_sorted(values + (i * 5), count % 5);
		++i;
	}
	free(medians);
	return (find_pivot(medians, max_group, ret));
}

int	median(int *values, size_t count, int *ret)
{
	return (find_pivot(values, count, ret));
}