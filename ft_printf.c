/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:28:17 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/11 14:47:48 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 'd' || format == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 's')
		length += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'x' || format == 'X')
		length += ft_printhex(va_arg(args, int), format);
	else if (format == 'p')
		length += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		length += ft_unsigned(va_arg(args, unsigned int));
	else if (format == '%')
		length += ft_putchar_fd('%', 1);
	return (length);
}

int	ft_printf(const char	*str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	int		y;

	va_start(args, str);
	print_length = 0;
	i = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			y = ft_formats(str[i + 1], args);
			if (y == -1)
				return (-1);
			print_length += y;
			i++;
		}
		else
			print_length += ft_putchar_fd(str[i], 1);
		i++;
	}
	return (print_length);
}
