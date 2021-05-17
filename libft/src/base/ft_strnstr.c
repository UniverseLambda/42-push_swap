/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:08:06 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:08:07 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	index;

	index = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (*str != 0 && len > 0)
	{
		index = 0;
		while (1)
		{
			if (index > len || (str[index] != to_find[index] && to_find[index]))
			{
				index = 0;
				break ;
			}
			if (to_find[index] == 0)
				break ;
			++index;
		}
		if (index != 0)
			return ((char *)str);
		++str;
		--len;
	}
	return (NULL);
}
