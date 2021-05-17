/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:43:01 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/04 11:43:02 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printers.h>

int64_t	ft_precision(int64_t d_count, uint64_t nb, t_parsing_result res)
{
	if ((res.flags & F_PRECISION))
	{
		if ((d_count < res.precision) && res.type != 'p')
			return (res.precision);
		if (!(res.precision) && nb == 0)
			return (0);
	}
	return (d_count);
}
