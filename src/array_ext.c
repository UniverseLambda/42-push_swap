#include <array.h>

t_aref	awrap(int *ptr, size_t len)
{
	t_aref	ref;

	ref.ptr = ptr;
	ref.length = len;
	ref.nofree = 1;
	return (ref);
}

size_t	alen(t_aref ref)
{
	return (ref.length);
}
