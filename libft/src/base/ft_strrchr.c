/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:07:34 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:07:35 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*last_occurence;

	index = 0;
	last_occurence = NULL;
	while (1)
	{
		if (s[index] == (char)c)
		{
			last_occurence = (char *)s + index;
		}
		if (s[index] == 0)
		{
			break ;
		}
		++index;
	}
	return (last_occurence);
}
