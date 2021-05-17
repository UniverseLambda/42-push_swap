/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:11:24 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:11:25 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	result = malloc(s1_length + s2_length + 1);
	if (result != NULL)
	{
		ft_strlcpy(result, s1, s1_length + 1);
		ft_strlcpy(result + s1_length, s2, s2_length + 1);
	}
	return (result);
}
