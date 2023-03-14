/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:53:44 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/14 17:20:14 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_error(int coins, int player, int end)
{
	if (coins == 0)
	{
		ft_printf("Error\n	%s\n", "No coins!");
		return (1);
	}
	if (player == 0 || player > 1)
	{
		ft_printf("Error\n	%s\n", "Wrong number of players!");
		return (1);
	}
	if (end == 0 || end > 1)
	{
		ft_printf("Error\n	%s\n", "Wrong number of exits");
		return (1);
	}
	return (0);
}

int	ft_check_game(char **map, int i, int j)
{
	int	coins;
	int	player;
	int	end;

	coins = 0;
	end = 0;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				coins++;
			if (map[i][j] == 'E')
				end++;
			if (map[i][j] == 'P')
				player++;
		}
	}
	return (ft_game_error(coins, player, end));
}

int	ft_check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				j++;
			else if (map[i][j] == 'E')
				j++;
			else if (map[i][j] == 'C')
				j++;
			else if (map[i][j] == '1')
				j++;
			else if (map[i][j] == '0' || map[i][j] == 'V')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_map(char **map)
{
	if (map[0] == NULL)
		return (1 && ft_printf("Error\n	%s\n", "Empy map!"));
	if (ft_check_shape(map) == 2)
	{
		ft_printf("Error\n	%s\n", "Missing walls!");
		return (1);
	}
	if (ft_check_shape(map) == 1)
	{
		ft_printf("Error\n	%s\n", "Map is not rectangular!");
		return (1);
	}
	if (ft_check_char(map) == 1)
	{
		ft_printf("Error\n	%s\n", "Wrong characters in the map!");
		return (1);
	}
	if (ft_check_game(map, -1, -1) == 1)
		return (1);
	if (ft_check_path(map, ft_coins_count(map)) == 1)
	{
		ft_printf("Error\n	%s\n", "No valid path!");
		return (1);
	}
	return (0);
}

int	check_map_start(char *arg)
{
	int		fd;
	int		i;
	char	*tmp;
	char	*map[500];

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\n	%s\n", "Can't read/find map");
		return (1);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL && tmp[0] != '\0')
	{
		map[i++] = ft_copy_to_map(tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	map[i] = NULL;
	fd = ft_check_map(map);
	clean_map(map);
	return (fd);
}
