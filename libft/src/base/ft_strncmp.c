/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:44:27 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:44:28 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	const unsigned char	*c1 = (unsigned char *)s1;
	const unsigned char	*c2 = (unsigned char *)s2;

	if (s1 == s2)
		return (0);
	index = 0;
	while (index < n)
	{
		if (c1[index] != c2[index])
		{
			return (c1[index] - c2[index]);
		}
		if (c1[index] == 0)
		{
			break ;
		}
		++index;
	}
	return (0);
}
