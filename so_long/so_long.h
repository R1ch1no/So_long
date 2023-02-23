/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:44:46 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/18 23:06:02 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//mapcheck
char			*ft_copy_to_map(char *tmp);
void			ft_copy_map(char **tmp, char **map);
void			clean_map(char **map);
int				ft_check_shape(char **map);
int				ft_check_walls(char **map, int height);
int				ft_game_error(int coins, int player, int end);
int				ft_check_game(char **map, int i, int j);
int				ft_check_char(char **map);
int				ft_check_map(char **map);
int				check_map_start(char *arg);
int				ft_possible_move(char **map, int y, int x);
int				ft_spread_player(char **map, int y, int x);
int				ft_check_end(char **map_cpy, int coins, int collect);
int				ft_check_path(char **map, int collect);
int				check_input(char *map, int argc);
int				ft_coins_count(char **map);
char			*ft_strj(char const *s1, char const *s2);

typedef struct s_imgs
{
	void		*ground;
	void		*enemy;
	void		*end;
	void		*endf;
	void		*coin;
	void		*mariol;
	void		*marior;
	void		*wall;
	void		*dead;
}				t_imgs;

typedef struct s_window
{
	void		*ptr;
	void		*win;
}				t_window;

typedef struct s_game
{
	t_imgs		img;
	t_window	window;
	char		**map;
	int			movedl;
	int			mapx;
	int			mapy;
	int			life;
	int			size;
	int			moves;
	int			fin;
	int			playery;
	int			playerx;
	int			collect;
	int			collected;
	int			endx;
	int			endy;
	int			y;
}				t_game;

//so_long
void			ft_make_map(t_game *map, char *file);
void			ft_window_size(t_game *game);
void			ft_print_map2(t_game *game);
void			ft_print_mapl(t_game *game);
void			ft_print_mapr(t_game *game);
void			ft_clean_all(t_game *game);
void			ft_img_init(t_game *game);
int				handle_no_event(void *data);
void			clean_map2(char **map);
void			ft_up(t_game *game);
void			ft_down(t_game *game);
void			ft_left(t_game *game);
void			ft_right(t_game *game);
void			ft_player_position(t_game *game);
void			ft_end_position(t_game *game);
void			ft_finished(t_game *game);
void			ft_print_mape(t_game *game);
void			ft_dead(t_game *game, char c);
void			ft_win(t_game *game, char c);
void			ft_text_handle(t_game *game);
void			ft_done(t_game *game);

#endif
