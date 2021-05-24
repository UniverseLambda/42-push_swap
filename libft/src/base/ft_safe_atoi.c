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

static int	ft_isspace(int c)
{
	return (c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v'
		|| c == ' ');
}

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

int	ft_safe_atoi(int *ret, const char *nptr)
{
	int					result;
	unsigned int		val;
	int					index;
	int					sign;

	val = 0;
	index = 0;
	while (ft_isspace(nptr[index]))
		++index;
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
