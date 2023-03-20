/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:48:21 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/19 17:07:32 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_coins_count(char **map)
{
	int	i;
	int	j;
	int	coins;

	i = -1;
	coins = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				coins++;
		}
	}
	return (coins);
}

int	ft_possible_move(char **map, int y, int x)
{
	if (map[y][x] == 'P' &&
		(map[y][x + 1] == 'C' || map[y][x + 1] == '0' || map[y - 1][x] == 'C'
				|| map[y - 1][x] == '0' || map[y][x - 1] == 'C' || map[y][x
				- 1] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == '0'))
		return (1);
	return (0);
}

int	ft_spread_player(char **map, int y, int x)
{
	if (map[y][x] == 'C' || map[y][x] == '0')
	{
		if (map[y][x] == 'C')
		{
			map[y][x] = 'P';
			return (1);
		}
		map[y][x] = 'P';
	}
	return (0);
}

int	ft_check_end(char **map_cpy, int coins, int collect)
{
	int	x;
	int	y;

	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (coins == collect && ((map_cpy[y][x] == 'E' && map_cpy[y][x
					+ 1] == 'P' && coins == collect) ||
					((map_cpy[y][x] == 'E' && map_cpy[y][x - 1] == 'P')
					|| (map_cpy[y][x] == 'E' && map_cpy[y - 1][x] == 'P')
					|| (map_cpy[y][x] == 'E' && map_cpy[y + 1][x] == 'P'))))
			{
				clean_map(map_cpy);
				return (0);
			}
			x++;
		}
		y++;
	}
	clean_map(map_cpy);
	return (1);
}

int	ft_check_path(char **map, int collect)
{
	int		x;
	int		y;
	int		coins;
	char	*map_cpy[500];

	ft_copy_map(map, map_cpy);
	coins = 0;
	y = 0;
	while (map_cpy[y])
	{
		x = -1;
		while (map_cpy[y][++x])
		{
			if (ft_possible_move(map_cpy, y, x) == 1)
			{
				coins += ft_spread_player(map_cpy, y + 1, x);
				coins += ft_spread_player(map_cpy, y - 1, x);
				coins += ft_spread_player(map_cpy, y, x + 1);
				coins += ft_spread_player(map_cpy, y, x - 1);
				y = 0;
			}
		}
		y++;
	}
	return (ft_check_end(map_cpy, coins, collect));
}
