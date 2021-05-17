/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:09:09 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:09:10 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

#include <stdlib.h>

/*
** TODO: Decides whether len should be 0 or remain the same if start is after
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	original_length;
	char	*sub;

	original_length = ft_strlen(s);
	if (start < original_length)
	{
		if (len > (original_length - start))
			len = (original_length - start);
	}
	else
	{
		len = 0;
	}
	sub = malloc(len + 1);
	if (sub != NULL)
	{
		sub[len] = 0;
		while (len-- > 0)
		{
			sub[len] = (s + start)[len];
		}
	}
	return (sub);
}
