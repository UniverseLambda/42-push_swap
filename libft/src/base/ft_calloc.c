/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:03:25 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:03:26 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include <ft_stdlib.h>
#include <ft_string.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	real_size;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	real_size = nmemb * size;
	if (real_size / size != nmemb)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(real_size);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, real_size);
	}
	return (ptr);
}
