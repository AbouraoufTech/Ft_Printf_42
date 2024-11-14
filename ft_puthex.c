/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:47:59 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/08 15:23:38 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned int n, char format)
{
	if (n > 15)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else if (n < 16 && n > 9)
	{
		if (format == 'x')
			ft_putchar_fd((n - 10) + 'a', 1);
		else if (format == 'X')
			ft_putchar_fd((n - 10) + 'A', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_printhex(unsigned int n, char format)
{
	int	len;

	len = ft_putlen(n);
	ft_puthex(n, format);
	return (len);
}
