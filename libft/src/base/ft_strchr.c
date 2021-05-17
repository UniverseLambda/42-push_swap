/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:06:54 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:06:55 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (1)
	{
		if (s[index] == (char)c)
		{
			return ((char *)s + index);
		}
		if (s[index] == 0)
		{
			break ;
		}
		++index;
	}
	return (NULL);
}
