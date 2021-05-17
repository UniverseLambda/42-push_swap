/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:56 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:14:57 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <ft_list.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*it;
	t_list	*tmp;

	if (lst == NULL)
		return ;
	it = *lst;
	*lst = NULL;
	while (it != NULL)
	{
		tmp = it;
		it = it->next;
		ft_lstdelone(tmp, del);
	}
}
