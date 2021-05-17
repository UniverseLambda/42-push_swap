/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:02:02 by clsaad            #+#    #+#             */
/*   Updated: 2021/01/12 14:02:03 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

int	ft_lstpush_back(t_list **alist, void *data)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(data);
	if (new_elem == NULL)
		return (0);
	ft_lstadd_back(alist, new_elem);
	return (1);
}
