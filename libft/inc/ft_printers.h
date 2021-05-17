/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:54:53 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/02 17:54:53 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERS_H
# define FT_PRINTERS_H

# include <unistd.h>

# include <ft_parser.h>

void		wrc(char c);
int			ft_fill(char filler, ssize_t len);
int64_t		ft_precision(int64_t d_count, uint64_t nb, t_parsing_result res);

int			ft_printf_char(char c, t_parsing_result result);
int			ft_printf_str(char *str, t_parsing_result result);
int			ft_printf_snbr(long nb, t_parsing_result res);
int			ft_printf_unbr(unsigned long nb, t_parsing_result res);

#endif // FT_PRINTERS_H
