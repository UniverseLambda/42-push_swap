/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equals_ignore_case.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:14:41 by clsaad            #+#    #+#             */
/*   Updated: 2021/01/12 11:14:42 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_ctype.h>

int	ft_equals_ignore_case(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (ft_tolower(*s1) != ft_tolower(*s2))
			return (0);
		++s1;
		++s2;
	}
	return (1);
}
