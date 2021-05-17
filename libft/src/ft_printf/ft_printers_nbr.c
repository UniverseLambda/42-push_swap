/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:03:46 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/03 10:03:47 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_ctype.h>
#include <ft_norm.h>

#include <ft_stdio.h>
#include <ft_parser.h>
#include <ft_printers.h>

static void	print_digit(unsigned long digit, int caps)
{
	static char	*base = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (caps)
		ft_putchar_fd(ft_toupper(base[digit]), STDOUT_FILENO);
	else
		ft_putchar_fd(base[digit], STDOUT_FILENO);
}

static int	count_digits(unsigned long nb, int base)
{
	int	count;

	count = 1;
	while ((nb / base) != 0)
	{
		nb /= base;
		++count;
	}
	return (count);
}

static int	ft_putnbr(uint64_t nb, uint64_t digit_count, int base, int caps)
{
	uint64_t	tmp;
	int			char_count;
	uint64_t	index;

	char_count = 0;
	while (digit_count > 0)
	{
		tmp = nb;
		index = 0;
		while (++index < digit_count)
			tmp /= base;
		print_digit(tmp % base, caps);
		--digit_count;
		++char_count;
	}
	return (char_count);
}

int	ft_printf_unbr(unsigned long nb, t_parsing_result res)
{
	int		base;
	int64_t	digit_count;
	int		count;

	base = ft_tern_i(
			(res.type == 'X' || res.type == 'x' || res.type == 'p'), 16, 10);
	count = ft_tern_i((res.type == 'p'), 2, 0);
	digit_count = ft_precision(count_digits(nb, base), nb, res);
	if (!(res.flags & F_MINUS) && (digit_count + count < res.width))
		count += ft_fill(
				ft_tern_c(
					(res.flags & F_ZERO) && !(res.flags & F_PRECISION),
					'0', ' '),
				res.width - (digit_count + count));
	if (res.type == 'p')
		ft_putstr_fd("0x", STDOUT_FILENO);
	count += ft_putnbr(nb, digit_count, base, res.type == 'X');
	if ((res.flags & F_MINUS) && (count < res.width))
		count += ft_fill(' ', res.width - count);
	return (count);
}

int	ft_printf_snbr(long snb, t_parsing_result res)
{
	int			b;
	int64_t		digit_count;
	int			count;
	uint64_t	nb;

	b = ft_tern_i(ft_tolower(res.type) == 'x' || res.type == 'p', 16, 10);
	nb = ft_tern_u64((snb < 0), ~snb + 1, snb);
	count = ft_tern_i((snb < 0), 1, 0);
	digit_count = ft_precision(count_digits(nb, b), nb, res);
	if (snb < 0 && (res.flags & F_ZERO) && !(res.flags & F_PRECISION))
		ft_putstr_fd("-", STDOUT_FILENO);
	if (!(res.flags & F_MINUS) && (digit_count + count < res.width))
		count += ft_fill(
				ft_tern_c(
					(res.flags & F_ZERO) && !(res.flags & F_PRECISION),
					'0', ' '),
				res.width - (digit_count + count));
	if (snb < 0 && !((res.flags & F_ZERO) && !(res.flags & F_PRECISION)))
		ft_putstr_fd("-", STDOUT_FILENO);
	count += ft_putnbr(nb, digit_count, b, res.type == 'X');
	if ((res.flags & F_MINUS) && (count < res.width))
		count += ft_fill(' ', res.width - count);
	return (count);
}
