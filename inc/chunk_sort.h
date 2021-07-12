/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:26:45 by clsaad            #+#    #+#             */
/*   Updated: 2021/07/12 14:26:45 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_SORT_H
# define CHUNK_SORT_H

# include<lifo_stack.h>

enum	e_dir
{
	DIR_NOT_FOUND,
	DIR_ROTATE,
	DIR_REVERSE
};

enum e_dir	cs_nearest(t_lifo_stack *s, int max);
int			cs_get_min(t_lifo_stack *s);
int			cs_get_max(t_lifo_stack *s);

#endif // CHUNK_SORT_H
