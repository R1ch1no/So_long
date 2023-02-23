/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:44:45 by rkurnava          #+#    #+#             */
/*   Updated: 2022/11/09 20:28:58 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include  <stdio.h>

int	ft_formatter(va_list arguments, char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_putchar(37);
	else if (format == 'c')
		len += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		len += ft_putstr(va_arg(arguments, char *));
	else if (format == 'p')
		len += ft_putpoint(va_arg(arguments, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putdec(va_arg(arguments, int));
	else if (format == 'u')
		len += ft_putundec(va_arg(arguments, unsigned int));
	else if (format == 'x')
		len += ft_puthex(va_arg(arguments, unsigned int), 1);
	else if (format == 'X')
		len += ft_puthex(va_arg(arguments, unsigned int), 0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arguments;

	i = 0;
	len = 0;
	va_start(arguments, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formatter(arguments, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(arguments);
	return (len);
}

/* int	main(void)
{
	char	*x;
	int		i;

	x = "Hello fuckers and fuckettes";
	i = 123456789;
	ft_printf("M - percentage sign : %%\n", "hi");
	ft_printf("M - pointer adress : %p\n", 15);
	ft_printf("M - decimal number : %d\n", i);
	ft_printf("M - integer number : %i\n", i);
	ft_printf("M - unsigned integer : %u\n", i);
	ft_printf("M - lowercased hexadecimal: %x\n", i);
	ft_printf("M - uppercased hexadecimal : %X\n", i);
	printf("O - pointer adress : %p\n", 15);
	printf("O - decimal number : %d\n", i);
	printf("O - integer number : %i\n", i);
	printf("O - unsigned integer : %u\n", i);
	printf("O - lowercased hexadecimal : %x\n", i);
	printf("O - uppercased hexadecimal: %X\n", i);
	return (0);
} */