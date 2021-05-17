/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:47:30 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:47:31 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				index;
	const unsigned char	*csrc = src;
	unsigned char		*cdest;

	index = 0;
	cdest = dest;
	if (cdest == csrc)
	{
		return (dest);
	}
	while (index < n)
	{
		cdest[index] = csrc[index];
		if (csrc[index] == (unsigned char)c)
		{
			return (dest + index + 1);
		}
		++index;
	}
	return (NULL);
}
