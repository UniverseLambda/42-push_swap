#include <median.h>
#include <array.h>

#include <ft_norm.h>
#include <ft_string.h>

static void	sort(t_arrayref array)
{
	int		tmp;
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	while (i < array.length)
	{
		x = i;
		j = i + 1;
		while (j < array.length)
		{
			if (aget(array, x) < aget(array, j))
				x = j;
			++j;
		}
		tmp = aget(array, x);
		aput(array, x, aget(array, i));
		aput(array, i, tmp);
		++i;
	}
}

static void	fill_medians(t_arrayref medians, int *values, size_t count)
{
	size_t	i;
	size_t	len;
	int		buff[5];

	i = -1;
	while (++i < medians.length)
	{
		len = ft_min_i(5, count - (i * 5));
		ft_memcpy(buff, values + (i * 5), len * sizeof(*values));
		sort(awrap(buff, len));
		aput(medians, i, buff[len / 2]);
	}
}

static int	get_pivot(t_arrayref medians, int *pivot)
{
	if (medians.length <= 5)
	{
		sort(medians);
		*pivot = aget(medians, medians.length / 2);
		return (1);
	}
	else
	{
		if (median(medians.ptr, medians.length, medians.length / 2, pivot))
			return (1);
	}
	return (0);
}

static int	retrieve_the_median(t_arrayref array, int idx, int pivot, int *retv)
{
	t_arrayref	low;
	t_arrayref	high;
	int			k;
	int			ret;

	low = anew(med_low_length(array, pivot));
	high = anew(med_high_length(array, pivot));
	ret = 0;
	if (avalid(low) && avalid(high))
	{
		med_fill_low_high(array, low, high, pivot);
		k = low.length;
		if (idx < k)
			ret = (median(low.ptr, low.length, idx, retv));
		else if (idx > k)
			ret = (median(high.ptr, high.length, idx - k - 1, retv));
		else
		{
			ret = 1;
			*retv = pivot;
		}
	}
	afree(low);
	afree(high);
	return (ret);
}

int	median(int *values, size_t count, int idx, int *retv)
{
	t_arrayref	medians;
	int			pivot;
	int			ret;

	medians = anew(count / 5 + (count % 5 != 0));
	if (!avalid(medians))
		return (0);
	fill_medians(medians, values, count);
	ret = get_pivot(medians, &pivot);
	afree(medians);
	if (!ret)
		return (0);
	return (retrieve_the_median(awrap(values, count), idx, pivot, retv));
}
