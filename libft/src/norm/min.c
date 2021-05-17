/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:27:01 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/17 13:27:02 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_norm.h>

size_t	ft_min_zu(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

double	ft_min_d(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned long long	ft_min_ull(unsigned long long a, unsigned long long b)
{
	if (a < b)
		return (a);
	return (b);
}
