/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:05:57 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:05:58 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*cs;

	index = 0;
	cs = (unsigned char *)s;
	while (index < n)
	{
		if (cs[index] == (unsigned char)c)
		{
			return (cs + index);
		}
		++index;
	}
	return (NULL);
}
