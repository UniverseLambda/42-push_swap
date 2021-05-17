/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:44:57 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:44:58 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

static size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	size;

	size = 0;
	while (size < maxlen && str[size] != 0)
	{
		++size;
	}
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);
	const size_t	dst_len = ft_strnlen(dst, size);

	if (dst_len == size)
		return (dst_len + src_len);
	ft_strlcpy(dst + dst_len, src, size - dst_len);
	return (src_len + dst_len);
}
