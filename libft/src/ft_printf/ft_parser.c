/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:06:08 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/04 12:06:10 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_parser.h>

#include <ft_ctype.h>

static t_parsing_result	new_result(void)
{
	t_parsing_result	result;

	result.flags = 0;
	result.width = 0;
	result.precision = 0;
	result.type = 0;
	return (result);
}

static void	parse_precision(const char **fmt, t_parsing_result *res)
{
	if (ft_isdigit(**fmt) || **fmt == '*')
	{
		if (**fmt == '*')
		{
			++(*fmt);
			res->flags |= F_WSTAR;
		}
		else
			while (ft_isdigit(**fmt))
				res->width = (res->width * 10) + (*((*fmt)++) - '0');
	}
}

t_parsing_result	parse_format(const char **format)
{
	t_parsing_result	res;

	res = new_result();
	while (*(++(*format)) == '-' || (**format) == '0')
	{
		if (**format == '-')
			res.flags |= F_MINUS;
		else
			res.flags |= F_ZERO;
	}
	parse_precision(format, &res);
	if (**format == '.')
	{
		res.flags |= F_PRECISION;
		if (*(++(*format)) == '*')
		{
			++(*format);
			res.flags |= F_PSTAR;
		}
		else if (ft_isdigit(**format))
			while (ft_isdigit(**format))
				res.precision = (res.precision * 10) + (*((*format)++) - '0');
	}
	res.type = **format;
	return (res);
}
