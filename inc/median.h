/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:45:34 by clsaad            #+#    #+#             */
/*   Updated: 2021/05/24 14:45:35 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIAN_H
# define MEDIAN_H

# include <stddef.h>
# include <array.h>

int		median(int *values, size_t count, int idx, int *ret);
int		median_from_pivot(int *values, size_t count, int pivot, int *ret);

size_t	med_low_length(t_aref array, int pivot);
size_t	med_high_length(t_aref array, int pivot);

void	med_fill_low_high(t_aref array, t_aref low, t_aref high, int pivot);

#endif // MEDIAN_H
