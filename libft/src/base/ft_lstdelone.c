/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:18:49 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:18:49 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_list.h>

/*
** TODO: think about whether it is more convenient to SEGFAULT when `lst` is
** NULL or to ignore it.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		if (del != NULL)
		{
			del(lst->content);
		}
		free(lst);
	}
}
