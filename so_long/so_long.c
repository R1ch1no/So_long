/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:49:21 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:33:42 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_window(t_game *game)
{
	game->window.ptr = mlx_init();
	game->window.win = mlx_new_window(game->window.ptr, game->mapx * 43,
			game->mapy * 43, "It's me, Mario!");
}

int	ft_keys(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->window.ptr);
	if (game->y == 1)
	{
		if (game->life == 1 && game->y == 1)
		{
			game->moves++;
			ft_printf("%s%d\n", "Moves made: ", game->moves);
		}
		if (key == XK_Up || key == XK_w || key == XK_W)
			ft_up(game);
		if (key == XK_Down || key == XK_s || key == XK_S)
			ft_down(game);
		if (key == XK_Left || key == XK_a || key == XK_A)
			ft_left(game);
		if (key == XK_Right || key == XK_d || key == XK_D)
			ft_right(game);
	}
	else
		mlx_loop_end(game->window.ptr);
	return (0);
}

int	ft_close(t_game *game)
{
	mlx_loop_end(game->window.ptr);
	return (0);
}

int	ft_game_init(t_game *game, char *file)
{
	ft_make_map(game, file);
	ft_init_window(game);
	ft_img_init(game);
	ft_print_mapl(game);
	ft_printf("%s\n", "Game started");
	mlx_hook(game->window.win, 2, 1L << 0, &ft_keys, game);
	mlx_hook(game->window.win, 17, 0, &ft_close, game);
	mlx_loop(game->window.ptr);
	ft_printf("%s\n", "Game finished");
	ft_clean_all(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\n	%s\n", "Game allocation error!");
		return (0);
	}
	if (check_input(argv[1], argc) == 0)
	{
		return (ft_game_init(*(&game), argv[1]));
	}
	if (argc != 2)
	{
		ft_printf("Error\n	%s\n", "Wrong number of arguments!");
		ft_printf("	%s\n", "Don't forget map name with .ber");
	}
	return (0);
}
