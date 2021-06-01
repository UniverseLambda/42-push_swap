#include <median.h>
#include <array.h>

size_t	med_low_length(t_arrayref array, int pivot)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (i < array.length)
		n += aget(array, i++) < pivot;
	return (n);
}

size_t	med_high_length(t_arrayref array, int pivot)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (i < array.length)
		n += aget(array, i++) > pivot;
	return (n);
}

void	med_fill_low_high(t_arrayref array, t_arrayref low, t_arrayref high, int pivot)
{
	size_t	i;
	size_t	li;
	size_t	hi;
	int		tmp;

	i = 0;
	li = 0;
	hi = 0;
	while (i < array.length)
	{
		tmp = aget(array, i);
		if (tmp < pivot)
			aput(low, li++, tmp);
		else if (tmp > pivot)
			aput(high, hi++, tmp);
		++i;
	}
}
