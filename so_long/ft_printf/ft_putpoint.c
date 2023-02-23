/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:19 by rkurnava          #+#    #+#             */
/*   Updated: 2022/11/09 19:33:14 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_swap(char *fin)
{
	int		i;
	int		j;
	int		len;
	char	tmp;

	i = 0;
	j = ft_strlen(fin) - 1;
	while (i < j)
	{
		tmp = fin[i];
		fin[i] = fin[j];
		fin[j] = tmp;
		i++;
		j--;
	}
	i = -1;
	while (fin[++i])
		ft_putchar(fin[i]);
	len = ft_strlen(fin);
	return (len);
}

static int	ft_check(unsigned long long p, char *str)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		return (ft_swap(str));
}

int	ft_putpoint(unsigned long long p)
{
	unsigned long long	tmp;
	int					remainder;
	int					i;
	char				res[500];

	tmp = p;
	i = 0;
	while (p != 0)
	{
		remainder = p % 16;
		if (remainder < 10)
			remainder = remainder + 48;
		else
			remainder = remainder + 87;
		res[i] = (char)remainder;
		p = p / 16;
		i++;
	}
	res[i] = 'x';
	res[i + 1] = '0';
	res[i + 2] = '\0';
	return (ft_check(tmp, res));
}
