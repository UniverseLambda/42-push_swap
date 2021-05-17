/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:30:04 by clsaad            #+#    #+#             */
/*   Updated: 2021/01/04 17:30:05 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*us1 = (unsigned char *)s1;
	const unsigned char	*us2 = (unsigned char *)s2;
	size_t				index;

	index = 0;
	if (s1 == s2)
		return (0);
	while (us1[index] == us2[index] && us1[index] != '\0')
		++index;
	return (us1[index] - us2[index]);
}
