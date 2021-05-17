/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:09:24 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/17 12:09:25 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_norm.h>

char	ft_tern_c(int cond, char a, char b)
{
	if (cond)
		return (a);
	return (b);
}

int	ft_tern_i(int cond, int a, int b)
{
	if (cond)
		return (a);
	return (b);
}

uint64_t	ft_tern_u64(int cond, uint64_t a, uint64_t b)
{
	if (cond)
		return (a);
	return (b);
}

double	ft_tern_d(int cond, double a, double b)
{
	if (cond)
		return (a);
	return (b);
}
