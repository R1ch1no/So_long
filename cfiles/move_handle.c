/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:31 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 12:17:30 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_down(t_game *game)
{
	int	x;
	int	y;

	x = game->playerx;
	y = game->playery;
	ft_dead(game, 's');
	ft_win(game, 's');
	if ((game->y == 1) && (game->map[y + 1][x] == '0' || game->map[y
			+ 1][x] == 'C'))
	{
		if (game->map[y + 1][x] == 'C')
			game->collected++;
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->playery++;
		ft_finished(game);
	}
	if (game->movedl == 1)
		ft_print_mapl(game);
	else
		ft_print_mapr(game);
	ft_text_handle(game);
}

void	ft_up(t_game *game)
{
	int	x;
	int	y;

	x = game->playerx;
	y = game->playery;
	ft_dead(game, 'w');
	ft_win(game, 'w');
	if ((game->y == 1) && (game->map[y - 1][x] == '0' || game->map[y
			- 1][x] == 'C'))
	{
		if (game->map[y - 1][x] == 'C')
			game->collected++;
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->playery--;
		ft_finished(game);
	}
	if (game->movedl == 1)
		ft_print_mapl(game);
	else
		ft_print_mapr(game);
	ft_text_handle(game);
}

void	ft_left(t_game *game)
{
	int	x;
	int	y;

	x = game->playerx;
	y = game->playery;
	game->movedl = 1;
	ft_dead(game, 'l');
	ft_win(game, 'l');
	if ((game->y == 1) && (game->map[y][x - 1] == '0' || game->map[y][x
		- 1] == 'C'))
	{
		if (game->map[y][x - 1] == 'C')
			game->collected++;
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->playerx--;
		ft_finished(game);
	}
	if (game->y == 1)
		ft_print_mapl(game);
	ft_text_handle(game);
}

void	ft_right(t_game *game)
{
	int		x;
	int		y;

	x = game->playerx;
	y = game->playery;
	ft_dead(game, 'r');
	ft_win(game, 'r');
	game->movedl = 0;
	if ((game->y == 1) && (game->map[y][x + 1] == '0' || game->map[y][x
		+ 1] == 'C'))
	{
		if (game->map[y][x + 1] == 'C')
			game->collected++;
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->playerx++;
		ft_finished(game);
	}
	if (game->y == 1)
		ft_print_mapr(game);
	ft_text_handle(game);
}
