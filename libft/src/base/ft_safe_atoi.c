/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:59:41 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/19 13:59:42 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include <ft_stdlib.h>
#include <ft_ctype.h>

static int	subsatoi(unsigned int *val, int index, const char *nptr)
{
	if (!ft_isdigit(nptr[index]))
		return (0);
	while (ft_isdigit(nptr[index]))
	{
		if ((*val) > ((*val) * 10) + (nptr[index] - '0'))
			return (0);
		(*val) = ((*val) * 10) + (nptr[index] - '0');
		++index;
	}
	return (1);
}

static int	check_chars(const char *nptr)
{
	size_t	i;

	i = (*nptr == '+' || *nptr == '-');
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

int	ft_safe_atoi(int *ret, const char *nptr)
{
	int					result;
	unsigned int		val;
	int					index;
	int					sign;

	val = 0;
	index = 0;
	if (!check_chars(nptr))
		return (0);
	sign = nptr[index] == '-';
	if (nptr[index] == '+' || nptr[index] == '-')
		++index;
	if (!subsatoi(&val, index, nptr))
		return (0);
	if ((val > INT_MAX && !sign) || ((val - 1) > (INT_MAX) && sign))
		return (0);
	result = val;
	if (sign)
		result = ~(val - 1);
	*ret = result;
	return (1);
}
