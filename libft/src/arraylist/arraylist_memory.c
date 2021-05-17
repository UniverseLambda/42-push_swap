/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:40:34 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/12 12:40:34 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arraylist.h>

#include <stdlib.h>

#include <ft_stdlib.h>
#include <ft_string.h>

int	arraylist_reserve(t_arraylist *list, size_t reservesize)
{
	if (list->capacity >= reservesize)
		return (1);
	return (arraylist_resize(list, reservesize));
}

int	arraylist_resize(t_arraylist *list, size_t newsize)
{
	void	*new_ptr;

	if (list->capacity == newsize)
		return (1);
	new_ptr = list->falloc(newsize, list->elemsize);
	if (new_ptr == NULL)
		return (0);
	if (newsize < list->elemcount)
	{
		ft_memcpy(new_ptr, list->data, newsize * list->elemsize);
		list->elemcount = newsize;
	}
	else
		ft_memcpy(new_ptr, list->data, list->elemcount * list->elemsize);
	list->ffree(list->data);
	list->capacity = newsize;
	list->data = new_ptr;
	return (1);
}

int	arraylist_trim(t_arraylist *list)
{
	return (arraylist_resize(list, list->elemcount));
}
