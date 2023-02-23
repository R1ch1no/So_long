/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:54:22 by rkurnava          #+#    #+#             */
/*   Updated: 2023/02/23 14:04:46 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_shape(char **map)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while ((map[0][width] != '\0') && (map[0][width] != '\n'))
		width++;
	while (map[height])
	{
		if ((map[height][0]) != '1' || (map[height][width] != '\n'))
			return (1);
		height++;
	}
	if (ft_check_walls(map, height - 1) == 1)
		return (2);
	return (0);
}

int	ft_check_walls(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while ((map[0][i] != '\0') && (map[0][i] != '\n'))
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	j = 1;
	while (map[j] && j < height)
	{
		if (map[j][0] != '1' || map[j][i - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	while ((map[height][i] != '\0') && (map[height][i] != '\n'))
	{
		if (map[height][i] != '1')
			return (1);
		i++;
	}
	return (0);
}
