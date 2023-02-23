/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:14:12 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:16:16 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_intlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num / 10)
	{
		len++;
		num = num / 10;
	}
	return (len + 1);
}

static char	*ft_putnbr(int nb, char *str, int l, int ilen)
{
	if (nb == -2147483648)
	{
		l++;
		ft_putnbr(nb / 10, str, l, ilen);
		str[ilen - l] = '8';
	}
	else if (nb < 0)
	{
		ft_putnbr(-nb, str, l, ilen);
	}
	else if (nb > 9)
	{
		l++;
		ft_putnbr(nb / 10, str, l, ilen);
		str[ilen - l] = 48 + nb % 10;
	}
	else
	{
		l++;
		str[ilen - l] = (48 + nb % 10);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*istr;
	int		ilen;
	int		l;

	ilen = ft_intlen(n);
	istr = malloc(ilen + 1);
	l = 0;
	if (!istr)
		return (NULL);
	if (n < 0)
	{
		istr[0] = '-';
	}
	istr = ft_putnbr(n, istr, l, ilen);
	istr[ilen] = '\0';
	return (istr);
}

void	ft_text_handle2(t_game *game)
{
	if (game->life == 1 && game->y == 0)
	{
		mlx_string_put(game->window.ptr, game->window.win, ((game->mapx * 43)
				/ 3), ((game->mapy * 43) - 25),
			(255 << 16 | 255 << 8 | 255), ("You won ! :)"));
		ft_printf("%s\n", "You won ! :)");
	}
}

void	ft_text_handle(t_game *game)
{
	char	*moves;

	if (game->y == 1)
	{
		moves = ft_itoa(game->moves);
		mlx_string_put(game->window.ptr, game->window.win, (((game->mapx * 43)
					/ 3) - 35), ((game->mapy * 43) - 21),
			(255 << 16 | 255 << 8 | 255), ("Moves made: "));
		mlx_string_put(game->window.ptr, game->window.win, (((game->mapx * 43)
					/ 3) + 35), ((game->mapy * 43) - 21),
			(255 << 16 | 255 << 8 | 255), moves);
		free(moves);
	}
	if (game->life == 0)
	{
		mlx_string_put(game->window.ptr, game->window.win, ((game->mapx * 43)
				/ 3), ((game->mapy * 43) - 25),
			(255 << 16 | 255 << 8 | 255), ("R.I.P. :/"));
		ft_printf("%s\n", "R.I.P. :/");
	}
	ft_text_handle2(game);
}
