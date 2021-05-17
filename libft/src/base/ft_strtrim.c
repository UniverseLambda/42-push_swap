/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:12:07 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:12:08 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_string.h>

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	index;
	int		found;

	start = 0;
	while (s1[start] != 0)
	{
		found = 0;
		index = 0;
		while (set[index] != 0)
		{
			if (s1[start] == set[index])
			{
				found = 1;
				break ;
			}
			++index;
		}
		if (!found)
		{
			return (start);
		}
		++start;
	}
	return (start);
}

static size_t	get_end(char const *s1, char const *set, size_t start)
{
	size_t	end;
	size_t	index;
	int		found;

	end = ft_strlen(s1);
	while (end > start)
	{
		found = 0;
		index = 0;
		while (set[index] != 0)
		{
			if (s1[end - 1] == set[index])
			{
				found = 1;
				break ;
			}
			++index;
		}
		if (!found)
		{
			break ;
		}
		--end;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = get_start(s1, set);
	end = get_end(s1, set, start);
	result = malloc(end - start + 1);
	if (result != NULL)
	{
		ft_strlcpy(result, s1 + start, end - start + 1);
	}
	return (result);
}
