#include <array.h>

#include <ft_stdlib.h>
#include <stdlib.h>

t_arrayref	anew(size_t size)
{
	t_arrayref	ref;

	ref.ptr = ft_calloc(size, sizeof(*(ref.ptr)));
	ref.length = size;
	ref.nofree = 0;
	return (ref);
}

void	afree(t_arrayref ref)
{
	if (!avalid(ref))
		return ;
	if (ref.nofree)
		return ;
	free(ref.ptr);
}

int	aget(t_arrayref ref, size_t index)
{
	if (!avalid(ref))
		return (0);
	if (index >= ref.length)
		return (0);
	return (ref.ptr[index]);
}

int	aput(t_arrayref ref, size_t index, int val)
{
	if (!avalid(ref))
		return (0);
	if (index >= ref.length)
		return (0);
	ref.ptr[index] = val;
	return (1);
}

int	avalid(t_arrayref ref)
{
	return (ref.ptr != NULL);
}
