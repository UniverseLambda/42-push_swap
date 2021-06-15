#include <array.h>

#include <ft_stdlib.h>
#include <ft_string.h>

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

t_aref	asharedsub(t_aref ref, size_t start, size_t end)
{
	t_aref	res;
	
	if (!avalid(ref))
		return (ainvalid());
	if (end < start)
		return (ainvalid());
	res.ptr = ref.ptr + start;
	res.length = end - start;
	res.nofree = 1;
	return (res);
}

t_aref	asub(t_aref ref, size_t start, size_t end)
{
	t_aref	res;

	if (!avalid(ref))
		return (ainvalid());
	if (end < start)
		return (ainvalid());
	res.length = end - start;
	res.ptr = ft_calloc(res.length, sizeof(*(res.ptr)));
	res.nofree = 0;
	if (res.ptr)
		ft_memcpy(res.ptr, ref.ptr + start, res.length * sizeof(*(res.ptr)));
	return (res);
}

t_aref	ainvalid()
{
	t_aref	res;

	res.length = 0;
	res.nofree = 1;
	res.ptr = NULL;
	return (res);
}
