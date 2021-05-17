/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:46:24 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:47:23 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dup;
	unsigned int	dup_index;

	dup = ft_strdup(s);
	if (dup != NULL)
	{
		dup_index = 0;
		while (dup[dup_index])
		{
			dup[dup_index] = f(dup_index, dup[dup_index]);
			++dup_index;
		}
	}
	return (dup);
}
