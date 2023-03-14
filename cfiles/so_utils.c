/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:45 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:14:29 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->playery = y;
				game->playerx = x;
			}
			x++;
		}
		y++;
	}
}

void	ft_img_init(t_game *game)
{
	game->moves = 0;
	game->y = 1;
	game->movedl = 1;
	game->life = 1;
	game->collected = 0;
	game->img.ground = mlx_xpm_file_to_image(game->window.ptr, "./imgs/bg.xpm",
			&game->size, &game->size);
	game->img.enemy = mlx_xpm_file_to_image(game->window.ptr, "./imgs/en.xpm",
			&game->size, &game->size);
	game->img.end = mlx_xpm_file_to_image(game->window.ptr, "./imgs/ex.xpm",
			&game->size, &game->size);
	game->img.coin = mlx_xpm_file_to_image(game->window.ptr, "./imgs/cn.xpm",
			&game->size, &game->size);
	game->img.mariol = mlx_xpm_file_to_image(game->window.ptr, "./imgs/ml.xpm",
			&game->size, &game->size);
	game->img.marior = mlx_xpm_file_to_image(game->window.ptr, "./imgs/mr.xpm",
			&game->size, &game->size);
	game->img.wall = mlx_xpm_file_to_image(game->window.ptr, "./imgs/w.xpm",
			&game->size, &game->size);
	game->img.dead = mlx_xpm_file_to_image(game->window.ptr, "./imgs/y.xpm",
			&game->size, &game->size);
	game->img.endf = mlx_xpm_file_to_image(game->window.ptr, "./imgs/exe.xpm",
			&game->size, &game->size);
}

void	ft_dead(t_game *game, char c)
{
	int	x;
	int	y;

	x = game->playerx;
	y = game->playery;
	if ((game->map[y + 1][x] == 'V' && c == 's') || (game->map[y - 1][x] == 'V'
			&& c == 'w') || (game->map[y][x - 1] == 'V' && c == 'l')
		|| (game->map[y][x + 1] == 'V' && c == 'r'))
	{
		game->y = 0;
		game->life = 0;
		if (game->map[y + 1][x] == 'V' && c == 's')
			game->map[y + 1][x] = 'D';
		if (game->map[y - 1][x] == 'V' && c == 'w')
			game->map[y - 1][x] = 'D';
		if (game->map[y][x - 1] == 'V' && c == 'l')
			game->map[y][x - 1] = 'D';
		if (game->map[y][x + 1] == 'V' && c == 'r')
			game->map[y][x + 1] = 'D';
		game->map[y][x] = '0';
		ft_print_mape(game);
	}
}

void	ft_win(t_game *game, char c)
{
	int	x;
	int	y;

	x = game->playerx;
	y = game->playery;
	if ((game->map[y + 1][x] == 'Y' && c == 's') || (game->map[y - 1][x] == 'Y'
			&& c == 'w') || (game->map[y][x - 1] == 'Y' && c == 'l')
		|| (game->map[y][x + 1] == 'Y' && c == 'r'))
	{
		game->y = 0;
		game->map[y][x] = '0';
		ft_print_mape(game);
	}
}
