/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_ret.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:14:31 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/26 10:14:32 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_norm.h"

void	*set_ptr(void *target, void *value)
{
	*((void **)target) = value;
	return (value);
}

int	set_i(int *target, int value)
{
	*target = value;
	return (value);
}

int	set_uc(unsigned char *target, unsigned char value)
{
	*target = value;
	return (value);
}
