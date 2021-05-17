/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:25:57 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/01 17:25:58 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdint.h>
# include <stddef.h>

# define F_ZERO			0x01
# define F_PRECISION	0x02
# define F_MINUS		0x04
# define F_WSTAR		0x08
# define F_PSTAR		0x10

typedef struct s_parsing_result
{
	uint8_t	flags;
	int64_t	width;
	int64_t	precision;
	uint8_t	type;
}					t_parsing_result;

t_parsing_result	parse_format(const char **format);

#endif // FT_PARSER_H
