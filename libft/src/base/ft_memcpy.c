/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:47:56 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:47:57 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == src)
	{
		return (dest);
	}
	while (n-- > 0)
	{
		((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
