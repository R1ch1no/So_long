/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:20 by rkurnava          #+#    #+#             */
/*   Updated: 2022/11/09 19:33:15 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
		while (str[++i])
			len += ft_putchar(str[i]);
	return (len);
}
