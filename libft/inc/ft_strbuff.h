/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:31:42 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/08 12:31:43 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRBUFF_H
# define FT_STRBUFF_H

typedef struct s_buff	t_buff;

t_buff					*create_buffer(void);
int						write_char_buffer(t_buff *buff, char c);
char					*merge_buffer(t_buff *buff);
void					destroy_buffer(t_buff *buff);

#endif // FT_STRBUFF_H
