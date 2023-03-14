/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:04:58 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:11:59 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clean_all(t_game *game)
{
	mlx_destroy_image(game->window.ptr, game->img.coin);
	mlx_destroy_image(game->window.ptr, game->img.end);
	mlx_destroy_image(game->window.ptr, game->img.enemy);
	mlx_destroy_image(game->window.ptr, game->img.ground);
	mlx_destroy_image(game->window.ptr, game->img.mariol);
	mlx_destroy_image(game->window.ptr, game->img.marior);
	mlx_destroy_image(game->window.ptr, game->img.wall);
	mlx_destroy_image(game->window.ptr, game->img.dead);
	mlx_destroy_image(game->window.ptr, game->img.endf);
	mlx_destroy_window(game->window.ptr, game->window.win);
	mlx_destroy_display(game->window.ptr);
	clean_map(game->map);
	free(game->map);
	free(game->window.ptr);
	free(game);
}

void	ft_end_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->endy = y;
				game->endx = x;
			}
			x++;
		}
		y++;
	}
}

void	ft_finished(t_game *game)
{
	int	y;
	int	x;

	y = game->endy;
	x = game->endx;
	if (game->collected == game->collect)
	{
		game->map[y][x] = 'Y';
	}
}

void	ft_print_mape(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.ground, (x * 43), (y * 43));
			else if (game->map[y][x] == 'D')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.dead, (x * 43), (y * 43));
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.coin, (x * 43), (y * 43));
		}
	}
	ft_print_map2(game);
}
