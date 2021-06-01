#include <array.h>

t_arrayref	awrap(int *ptr, size_t len)
{
	t_arrayref	ref;

	ref.ptr = ptr;
	ref.length = len;
	ref.nofree = 1;
	return (ref);
}

size_t	alen(t_arrayref ref)
{
	return (ref.length);
}
