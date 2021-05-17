/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:08:48 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:08:48 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft_string.h>
#include <ft_stdlib.h>

static unsigned int	ft_count_delimited(char const *string, char sep)
{
	char			previous_is_sep;
	unsigned int	seg_count;
	unsigned int	i;

	i = 0;
	seg_count = 0;
	previous_is_sep = -1;
	while (string[i])
	{
		if (string[i++] == sep)
		{
			if (!previous_is_sep && i != 0)
				++seg_count;
			previous_is_sep = 1;
		}
		else
			previous_is_sep = 0;
	}
	if (previous_is_sep == 0)
		++seg_count;
	return (seg_count);
}

static int	ft_split_core(char ***tab, char const *s, char c)
{
	unsigned int	sub_str_len;
	unsigned int	i;

	i = 0;
	*tab = ft_calloc((ft_count_delimited(s, c) + 1), sizeof(char *));
	while (*tab != NULL && s != NULL && *s != 0)
	{
		if (*s == c)
		{
			s++;
			continue ;
		}
		sub_str_len = 0;
		while (*s != c && *s != 0)
		{
			sub_str_len++;
			s++;
		}
		(*tab)[i] = ft_calloc((sub_str_len + 1), sizeof(char));
		if ((*tab)[i] == NULL)
			return (0);
		ft_strlcpy((*tab)[i++], s - sub_str_len, (sub_str_len + 1));
	}
	return (*tab != NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (!ft_split_core(&tab, s, c))
	{
		if (tab != NULL)
		{
			i = 0;
			while (tab[i] != NULL || tab[i] != 0)
				free(tab[i++]);
			free(tab);
		}
		return (NULL);
	}
	return (tab);
}
