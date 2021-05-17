/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:49:15 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:49:16 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest == src)
	{
		return (dest);
	}
	else if (dest > src)
	{
		return (ft_memcpy(dest, src, n));
	}
	while (index < n)
	{
		((char *)dest)[index] = ((char *)src)[index];
		++index;
	}
	return (dest);
}
