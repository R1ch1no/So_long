/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:13 by rkurnava          #+#    #+#             */
/*   Updated: 2022/11/09 20:17:27 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n)
	{
		if (n == -2147483648)
		{
			len += ft_putdec(n / 10);
			len += ft_putchar(56);
		}
		else if (n < 0)
		{
			len += ft_putchar('-');
			len += ft_putdec(-n);
		}
		else if (n > 9)
		{
			len += ft_putdec(n / 10);
			len += ft_putchar((48 + n % 10));
		}
		else
			len += ft_putchar((48 + n % 10));
	}
	return (len);
}

int	ft_putdec(long long n)
{
	if (n < -2147483648 || n > 2147483647 || n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (ft_putnbr(n));
}
