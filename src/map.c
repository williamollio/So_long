/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:38:22 by wollio            #+#    #+#             */
/*   Updated: 2021/10/19 15:18:43 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Free a two dimensional array */
void	double_free(char **map_split, t_map *l_map)
{
	int	i;

	i = 0;
	while (i < l_map->y + 1)
	{
		free(map_split[i]);
		i++;
	}
	free(map_split);
}

/* Verify that the map is rectangular */
int	map_line(char *map, t_map *l_map)
{
	int		i;
	char	**map_split;

	i = 1;
	map_split = ft_split(map, '\n');
	l_map->x = ft_strlen(map_split[0]);
	while (i < l_map->y + 1)
	{
		if ((int)ft_strlen(map_split[i]) != l_map->x)
		{
			double_free(map_split, l_map);
			return (0);
		}
		i++;
	}
	double_free(map_split, l_map);
	return (1);
}

/* Verify the elements in the map */
int	map_valid(t_map *l_map)
{
	if (l_map->c >= 1 && l_map->p == 1 && l_map->e >= 1
		&& l_map->x >= 1 && l_map->y >= 1)
		return (1);
	else
		return (0);
}

/* Verify if the format of the map is correct */
int	checkmap(char *map, int *width, int *height)
{
	t_map	l_map;

	map_init(&l_map);
	if (!(map_char(map, &l_map)) || !(map_wall(map, &l_map))
		|| !(map_line(map, &l_map)) || !(map_valid(&l_map)))
		return (0);
	*width = l_map.x;
	*height = l_map.y + 1;
	return (1);
}

/* Read the map and put it in a string */
char	*ft_map_to_string(char *map)
{
	int		fd;
	char	*str = NULL;
	char	*tmp;
	int		rt;
	char	buffer[2];

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	rt = read(fd, buffer, 1);
	while (rt)
	{
		buffer[rt] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
		rt = read(fd, buffer, 1);
	}
	return (str);
}
