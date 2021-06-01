#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>

typedef struct s_arrayref
{
	int			*ptr;
	size_t		length;
	int			nofree;
}				t_arrayref;

t_arrayref		anew(size_t size);
void			afree(t_arrayref ref);
int				aget(t_arrayref ref, size_t index);
int				aput(t_arrayref ref, size_t index, int val);
int				avalid(t_arrayref ref);
size_t			alen(t_arrayref ref);

t_arrayref		awrap(int *ptr, size_t len);

#endif // ARRAY_H
