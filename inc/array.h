#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>

typedef struct s_aref
{
	int			*ptr;
	size_t		length;
	int			nofree;
}				t_aref;

t_aref			anew(size_t size);
void			afree(t_aref ref);
int				aget(t_aref ref, size_t index);
int				aput(t_aref ref, size_t index, int val);
int				avalid(t_aref ref);
size_t			alen(t_aref ref);

t_aref			awrap(int *ptr, size_t len);

#endif // ARRAY_H
