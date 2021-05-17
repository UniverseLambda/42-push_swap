/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:43:04 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:43:05 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*c1 = s1;
	const unsigned char	*c2 = s2;

	if (s1 == s2)
		return (0);
	index = 0;
	while (index < n)
	{
		if (c1[index] != c2[index])
		{
			return (c1[index] - c2[index]);
		}
		++index;
	}
	return (0);
}
