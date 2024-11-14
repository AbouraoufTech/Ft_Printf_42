/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:42:40 by eabourao          #+#    #+#             */
/*   Updated: 2024/11/08 15:21:13 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ss1;

	if (!s1)
		return (NULL);
	ss1 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (ss1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ss1[i] = s1[i];
		i++;
	}
	ss1[i] = '\0';
	return (ss1);
}

static int	ft_num_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		s;
	long	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	s = ft_num_len(n) + 1;
	dest = (char *)malloc(sizeof(char) * s);
	if (!dest)
		return (NULL);
	s--;
	if (n < 0)
		num *= -1;
	dest[s--] = '\0';
	while (s > 0)
	{
		dest[s--] = (num % 10) + 48;
		num /= 10;
	}
	if (n < 0)
		dest[s] = '-';
	else
		dest[s] = (num % 10) + 48;
	return (dest);
}
