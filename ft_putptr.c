/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:11:37 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/08 15:20:19 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long n)
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

void	ft_putptr(unsigned long n)
{
	if (n > 15)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else if (n < 16 && n > 9)
	{
		ft_putchar_fd((n - 10) + 'a', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_printptr(unsigned long n)
{
	int	len;

	len = ft_ptrlen(n);
	ft_putstr_fd("0x", 1);
	ft_putptr(n);
	return (len + 2);
}
