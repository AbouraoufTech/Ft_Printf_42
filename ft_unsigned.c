/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:33:00 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/08 15:20:06 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoau(unsigned int n)
{
	char			*dest;
	int				s;
	unsigned int	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	s = ft_num_len_unsigned(n) + 1;
	dest = (char *)malloc(sizeof(char) * s);
	if (!dest)
		return (NULL);
	s--;
	dest[s--] = '\0';
	while (s > 0)
	{
		dest[s--] = (num % 10) + 48;
		num /= 10;
	}
	dest[s] = (num % 10) + 48;
	return (dest);
}

int	ft_unsigned(unsigned int n)
{
	char	*number;
	int		l;

	if (n == 0)
		return (ft_putchar_fd(n + 48, 1));
	number = ft_itoau(n);
	if (number == NULL)
		return (-1);
	l = ft_strlen(number);
	ft_putstr_fd(number, 1);
	free(number);
	return (l);
}
