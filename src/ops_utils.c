#include <ops.h>

#include <ps_runtime.h>

enum e_ops	*op_ptr(size_t i)
{
	return (arraylist_get(&(rt_ptr()->ops), i));
}
