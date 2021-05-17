/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:25:43 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/27 14:25:44 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_stdio.h>
#include <ft_printers.h>
#include <ft_parser.h>
#include <ft_ctype.h>

static int	ft_dispatch(t_parsing_result result, va_list args)
{
	if (result.type == 'c')
		return (ft_printf_char(va_arg(args, int), result));
	else if (result.type == 's')
		return (ft_printf_str(va_arg(args, char *), result));
	else if (result.type == 'd' || result.type == 'i')
		return (ft_printf_snbr(va_arg(args, int), result));
	else if (result.type == 'u' || ft_toupper(result.type) == 'X')
		return (ft_printf_unbr(va_arg(args, unsigned int), result));
	else if (result.type == 'p')
		return (ft_printf_unbr(va_arg(args, unsigned long), result));
	else if (result.type == '%')
		return (ft_printf_char('%', result));
	return (0);
}

static void	ft_interpret_result(t_parsing_result *result, va_list args)
{
	int				tmp;

	if (result->flags & F_WSTAR)
	{
		tmp = va_arg(args, int);
		if (tmp < 0)
		{
			tmp *= -1;
			result->flags |= F_MINUS;
		}
		result->width = tmp;
	}
	if (result->flags & F_PSTAR)
	{
		tmp = va_arg(args, int);
		if (tmp < 0)
			result->flags &= ~(F_PRECISION);
		else
			result->precision = tmp;
	}
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	args;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}

int	ft_vprintf(const char *format, va_list args)
{
	int					ccount;
	t_parsing_result	result;

	ccount = 0;
	while (*format)
	{
		if (*format == '%')
		{
			result = parse_format(&format);
			if (result.type == 0)
				continue ;
			ft_interpret_result(&result, args);
			ccount += ft_dispatch(result, args);
			++format;
			continue ;
		}
		ft_putchar_fd(*(format++), STDOUT_FILENO);
		++ccount;
	}
	return (ccount);
}
