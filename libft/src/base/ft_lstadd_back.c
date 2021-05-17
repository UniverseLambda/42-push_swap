/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:11 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:14:12 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <ft_list.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*it;

	it = *alst;
	if (it == NULL)
	{
		*alst = new;
		return ;
	}
	while (it->next != NULL)
	{
		it = it->next;
	}
	it->next = new;
}
