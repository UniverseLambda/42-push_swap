/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:06:19 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:06:20 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_stdio.h>

static void	print_digit(unsigned int digit, int fd)
{
	ft_putchar_fd((digit % 10) + '0', fd);
}

static int	count_digits(unsigned int nb)
{
	int	count;

	count = 1;
	while ((nb / 10) != 0)
	{
		nb /= 10;
		++count;
	}
	return (count);
}

static unsigned int	treat_and_cast_int(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		return ((unsigned int)(~nb + 1));
	}
	return ((unsigned int)nb);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	uval;
	unsigned int	temp_holder;
	int				digit_count;
	int				sub_index;

	uval = treat_and_cast_int(nb, fd);
	digit_count = count_digits(uval);
	while (--digit_count >= 0)
	{
		temp_holder = uval;
		sub_index = 0;
		while (sub_index++ < digit_count)
		{
			temp_holder /= 10;
		}
		temp_holder %= 10;
		print_digit(temp_holder, fd);
	}
}
