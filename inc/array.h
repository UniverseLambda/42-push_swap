/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:12:04 by clsaad            #+#    #+#             */
/*   Updated: 2021/06/29 10:12:05 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>

# include <ft_stdbool.h>

typedef struct s_aref
{
	int			*ptr;
	size_t		length;
	t_bool		nofree;
}				t_aref;

t_aref			anew(size_t size);
void			afree(t_aref ref);
int				aget(t_aref ref, size_t index);
t_bool			aput(t_aref ref, size_t index, int val);
t_bool			avalid(t_aref ref);
size_t			alen(t_aref ref);

t_aref			awrap(int *ptr, size_t len);
t_aref			asharedsub(t_aref ref, size_t start, size_t end);
t_aref			asub(t_aref ref, size_t start, size_t end);
t_aref			ainvalid();

#endif // ARRAY_H
