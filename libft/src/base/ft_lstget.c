/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:21:02 by clsaad            #+#    #+#             */
/*   Updated: 2021/01/07 15:21:03 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void	*ft_lstget(t_list *lst, size_t index)
{
	size_t	i;

	i = 0;
	while (lst != NULL && i < index)
	{
		lst = lst->next;
		++i;
	}
	if (lst != NULL)
		return (lst->content);
	return (NULL);
}
