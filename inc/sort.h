/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:44:47 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/24 11:44:48 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include <ps_runtime.h>
# include <ft_stdbool.h>

void	sort(void);
t_bool	quick_sort(t_runtime *rt);
t_bool	chunk_sort(t_runtime *rt);

#endif // SORT_H
