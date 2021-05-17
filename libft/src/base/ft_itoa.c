/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:02:51 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:02:52 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>

static size_t	itoa_size(int n)
{
	size_t			size;
	unsigned int	value;

	size = 1;
	if (n < 0)
		size = 2;
	value = n;
	if (n < 0)
		value = ~value + 1;
	while ((value / 10) != 0)
	{
		value /= 10;
		++size;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			offset;
	unsigned int	value;
	size_t			digit_count;

	digit_count = itoa_size(n);
	offset = 0;
	value = n;
	result = ft_calloc(digit_count--, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		--digit_count;
		result[offset++] = '-';
		value = ~value + 1;
	}
	while (digit_count-- > 0)
	{
		result[offset + digit_count] = (value % 10) + '0';
		value /= 10;
	}
	return (result);
}
