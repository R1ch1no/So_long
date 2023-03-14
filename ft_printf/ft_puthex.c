/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:17 by rkurnava          #+#    #+#             */
/*   Updated: 2022/11/09 19:36:26 by rkurnava         ###   ########.fr       */
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

static int	ft_swap(char *fin, int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(fin) - 1;
	len = ft_strlen(fin);
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
	return (len);
}

static int	ft_check(unsigned int num, char *str)
{
	int	len;

	len = 0;
	if (num <= 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_swap(str, len));
}

int	ft_puthex(unsigned int mem, int sign)
{
	int		tmp;
	int		remainder;
	int		i;
	char	res[500];

	tmp = mem;
	i = 0;
	while (mem != 0)
	{
		remainder = mem % 16;
		if (remainder < 10)
			remainder = remainder + 48;
		else if (remainder >= 10 && sign == 1)
			remainder = remainder + 87;
		else if (remainder >= 10 && sign == 0)
			remainder = remainder + 55;
		res[i++] = (char)remainder;
		mem = mem / 16;
	}
	res[i] = '\0';
	return (ft_check(tmp, res));
}
