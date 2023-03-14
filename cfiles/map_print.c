/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:35 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:13:49 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_mapr(t_game *game)
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
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.marior, (x * 43), (y * 43));
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.coin, (x * 43), (y * 43));
		}
	}
	ft_print_map2(game);
}

void	ft_print_map2(t_game *game)
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
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.wall, (x * 43), (y * 43));
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.end, (x * 43), (y * 43));
			else if (game->map[y][x] == 'V')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.enemy, (x * 43), (y * 43));
			else if (game->map[y][x] == 'Y')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.endf, (x * 43), (y * 43));
		}
	}
}

void	ft_print_mapl(t_game *game)
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
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.mariol, (x * 43), (y * 43));
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->window.ptr, game->window.win,
					game->img.coin, (x * 43), (y * 43));
		}
	}
	ft_print_map2(game);
}

void	ft_window_size(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while ((game->map[0][width] != '\0') && (game->map[0][width] != '\n'))
		width++;
	while (game->map[height])
		height++;
	game->mapx = width;
	game->mapy = height;
}

void	ft_make_map(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*dest;

	i = 0;
	dest = ft_strj("maps/", file);
	fd = open(dest, O_RDONLY);
	tmp = get_next_line(fd);
	game->map = malloc(500 * sizeof(char *));
	while (tmp != NULL)
	{
		game->map[i++] = ft_copy_to_map(tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	free(dest);
	close(fd);
	game->map[i] = NULL;
	ft_player_position(game);
	game->collect = ft_coins_count(game->map);
	ft_end_position(game);
	ft_window_size(game);
}
