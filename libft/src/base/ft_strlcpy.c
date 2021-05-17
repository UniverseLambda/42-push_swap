/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:48:36 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:48:37 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (dst == NULL || src == NULL)
		return (0);
	index = 0;
	while (size != 0 && src[index] != 0 && index < (size - 1))
	{
		dst[index] = src[index];
		++index;
	}
	if (size != 0)
		dst[index] = 0;
	return (ft_strlen(src));
}
