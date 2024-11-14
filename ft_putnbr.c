/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:50 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/07 17:37:17 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*number;
	int		l;

	if (n == 0)
		return (ft_putchar_fd(n + 48, 1));
	number = ft_itoa(n);
	if (!number)
		return (-1);
	l = ft_strlen(number);
	ft_putstr_fd(number, 1);
	free(number);
	return (l);
}
