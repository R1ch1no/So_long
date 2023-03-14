/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:49:41 by rkurnava          #+#    #+#             */
/*   Updated: 2023/03/14 17:11:53 by rkurnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_copy_to_map(char *tmp)
{
	int		i;
	char	*map;

	i = 0;
	map = (char *)malloc(ft_strlen(tmp) + 1);
	while (tmp[i])
	{
		map[i] = tmp[i];
		i++;
	}
	map[i] = '\0';
	return (map);
}

void	ft_copy_map(char **tmp, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (tmp[++i])
		map[i] = ft_copy_to_map(tmp[i]);
	map[i] = NULL;
	j = -1;
	while (tmp[++j])
	{
		i = -1;
		while (tmp[j][++i])
			map[j][i] = tmp[j][i];
		map[j][i] = '\0';
	}
}

void	clean_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
	}
}

char	*ft_strj(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*jstr;
	int		i;
	int		j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	if (!str2)
		return (str1);
	jstr = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!jstr)
		return (jstr);
	while (str1[i])
		jstr[j++] = str1[i++];
	i = 0;
	while (str2[i])
		jstr[j++] = str2[i++];
	jstr[j] = '\0';
	return (jstr);
}

int	check_input(char *map, int argc)
{
	char	*mapf;
	int		i;

	i = -1;
	if (argc == 2)
	{
		mapf = ft_strj("maps/", map);
		if (check_map_start(mapf) == 0)
		{
			while (mapf[++i])
			{
				if (mapf[i] == '.' && mapf[i + 1] == 'b' && mapf[i + 1] != '\0'
					&& mapf[i + 2] == 'e' && mapf[i + 2] != '\0' && mapf[i
						+ 3] == 'r' && mapf[i + 3] != '\0'
					&& mapf[i + 4] == '\0')
				{
					free(mapf);
					return (0);
				}
			}
			ft_printf("Error\n	%s\n", "Wrong map!");
		}
		free(mapf);
	}
	return (1);
}
