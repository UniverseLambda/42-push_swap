/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:50:20 by clsaad            #+#    #+#             */
/*   Updated: 2021/07/12 11:50:21 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "ps_runtime.h"
# include "ft_stdbool.h"

t_bool	check_are_uniques(t_runtime *rt);
t_bool	check_is_sorted(t_runtime *rt);

#endif // CHECKS_H
