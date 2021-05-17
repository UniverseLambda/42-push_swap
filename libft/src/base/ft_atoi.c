/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:45:44 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:45:46 by clsaad           ###   ########lyon.fr   */
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

static long long	ft_atoll(const char *nptr)
{
	long long			result;
	unsigned long long	val;
	int					index;
	int					sign;

	val = 0;
	index = 0;
	while (ft_isspace(nptr[index]))
		++index;
	sign = nptr[index] == '-';
	if (nptr[index] == '+' || nptr[index] == '-')
		++index;
	while (ft_isdigit(nptr[index]))
	{
		val = (val * 10) + (nptr[index] - '0');
		++index;
	}
	if (!val || (val > LLONG_MAX && !sign) || ((val - 1) > (LLONG_MAX) && sign))
		return (0);
	result = val;
	if (sign)
		result = ~(val - 1);
	return (result);
}

int	ft_atoi(const char *nptr)
{
	const long long	result = ft_atoll(nptr);

	if (result < INT_MIN || result > INT_MAX)
	{
		return (0);
	}
	return ((int)result);
}
