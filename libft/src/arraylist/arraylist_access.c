/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:57:50 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/12 11:57:51 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arraylist.h>

#include <ft_stdlib.h>
#include <ft_string.h>

/*
** I should implement a spinlock (or any other technique) to prevent concurrent
** modifications.
*/

void	*arraylist_newelem(t_arraylist *list)
{
	char	*elem_ptr;

	if (list->elemcount >= list->capacity)
	{
		list->elemcount = list->capacity;
		if (!arraylist_reserve(list, list->capacity * 2))
			return (NULL);
	}
	elem_ptr = (char *)(list->data) + (list->elemcount * list->elemsize);
	++(list->elemcount);
	ft_memset(elem_ptr, 0, list->elemsize);
	return (elem_ptr);
}

void	*arraylist_add(t_arraylist *list, void *elem)
{
	void	*elem_ptr;

	elem_ptr = arraylist_newelem(list);
	if (elem_ptr != NULL)
		ft_memcpy(elem_ptr, elem, list->elemsize);
	return (elem_ptr);
}

void	*arraylist_get(t_arraylist *list, size_t index)
{
	if (index >= list->elemcount)
		return (NULL);
	return ((char *)(list->data) + (list->elemsize * index));
}

void	arraylist_remove(t_arraylist *list, size_t index)
{
	char	*index_ptr;

	if (index >= list->elemcount)
		return ;
	if (index == (list->elemcount - 1))
	{
		--(list->elemcount);
		return ;
	}
	index_ptr = (char *)(list->data) + (index * list->elemsize);
	ft_memmove(
		index_ptr, index_ptr + (list->elemsize), list->elemcount - index - 1);
	--(list->elemcount);
}

void	arraylist_clear(t_arraylist *list)
{
	list->elemcount = 0;
	if (list->capacity <= 32)
		return ;
	arraylist_resize(list, 16);
}
