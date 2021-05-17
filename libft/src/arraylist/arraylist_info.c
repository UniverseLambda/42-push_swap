/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:10:01 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/12 13:10:02 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_arraylist.h>

void	*arraylist_data(t_arraylist *list)
{
	return (list->data);
}

size_t	arraylist_size(t_arraylist *list)
{
	return (list->elemcount);
}

size_t	arraylist_capacity(t_arraylist *list)
{
	return (list->capacity);
}
