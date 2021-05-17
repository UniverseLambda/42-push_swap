/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:10:55 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/12 11:10:56 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arraylist.h>

#include <stdlib.h>

#include <ft_string.h>
#include <ft_stdlib.h>

t_arraylist	*arraylist_new(size_t elemsize, t_calloc falloc, t_free ffree)
{
	t_arraylist	*result;

	if (falloc == NULL)
		result = ft_calloc(sizeof(t_arraylist), 1);
	else
		result = falloc(sizeof(t_arraylist), 1);
	if (result == NULL)
		return (NULL);
	if (!arraylist_init(result, elemsize, falloc, ffree))
	{
		if (ffree == NULL)
			free(result);
		else
			ffree(result);
		result = NULL;
	}
	return (result);
}

int	arraylist_init(t_arraylist *list, size_t elemsize,
					t_calloc falloc, t_free ffree)
{
	list->capacity = 16;
	list->elemsize = elemsize;
	list->elemcount = 0;
	if (falloc == NULL)
		list->falloc = ft_calloc;
	else
		list->falloc = falloc;
	if (ffree == NULL)
		list->ffree = free;
	else
		list->ffree = ffree;
	list->data = list->falloc(list->capacity, list->elemsize);
	if (list->data == NULL)
		return (0);
	ft_memset(list->data, 0, list->capacity * list->elemsize);
	return (1);
}

void	arraylist_freeres(t_arraylist *list)
{
	list->ffree(list->data);
	list->data = NULL;
	list->capacity = 0;
	list->elemcount = 0;
	list->elemsize = 0;
}

void	arraylist_destroy(t_arraylist *list)
{
	arraylist_freeres(list);
	list->ffree(list);
}
