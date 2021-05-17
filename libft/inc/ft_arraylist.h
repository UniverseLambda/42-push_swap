/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraylist.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:11:18 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/12 11:11:18 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAYLIST_H
# define FT_ARRAYLIST_H

# include <stddef.h>

# include "ft_stdlib.h"

typedef struct s_arraylist
{
	size_t		capacity;
	size_t		elemcount;
	size_t		elemsize;
	void		*data;
	t_calloc	falloc;
	t_free		ffree;
}			t_arraylist;

t_arraylist	*arraylist_new(size_t elemsize, t_calloc falloc, t_free ffree);
int			arraylist_init(t_arraylist *list, size_t elemsize,
				t_calloc falloc, t_free ffree);
void		arraylist_freeres(t_arraylist *list);
void		arraylist_destroy(t_arraylist *list);

void		*arraylist_newelem(t_arraylist *list);
void		*arraylist_add(t_arraylist *list, void *elem);
void		*arraylist_get(t_arraylist *list, size_t index);
void		arraylist_remove(t_arraylist *list, size_t index);
void		arraylist_clear(t_arraylist *list);

int			arraylist_reserve(t_arraylist *list, size_t reservesize);
int			arraylist_resize(t_arraylist *list, size_t newsize);
int			arraylist_trim(t_arraylist *list);

void		*arraylist_data(t_arraylist *list);
size_t		arraylist_size(t_arraylist *list);
size_t		arraylist_capacity(t_arraylist *list);

#endif // FT_ARRAYLIST_H
