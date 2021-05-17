/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minnz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:28:07 by clsaad            #+#    #+#             */
/*   Updated: 2021/03/17 13:28:09 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_minnz_ull(unsigned long long a, unsigned long long b)
{
	if (a < b && a)
		return (a);
	return (b);
}
