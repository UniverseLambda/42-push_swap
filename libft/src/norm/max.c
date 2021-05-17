/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:29:48 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/17 13:29:51 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_norm.h>

size_t	ft_max_zu(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned long long	ft_max_ull(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (a);
	return (b);
}

double	ft_max_d(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
