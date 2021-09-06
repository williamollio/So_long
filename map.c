/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:38:22 by wollio            #+#    #+#             */
/*   Updated: 2021/09/06 15:22:14 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *l_map)
{
	l_map->c = 0;
	l_map->e = 0;
	l_map->p = 0;
	l_map->x = 0;
	l_map->y = 0;
}

int map_char(char *map, t_map *l_map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		if (map[i] == 'C')
			l_map->c ++;
		else if (map[i] == 'E')
			l_map->e ++;
		else if (map[i] == 'P')
			l_map->p ++;
		else if (map[i] != '1' && map[i] != '0' && map[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void numberofline(char *map, t_map *l_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			l_map->y++;
		i++;
	}
	return;
}
int	map_wall(char *map, t_map *l_map)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	numberofline(map, l_map);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			lines++;
			if (map[i-1] != '1' || !((map[i+1] == '1') || (map[i+1] == '\0')))
				return (0);
		}
		if (lines == 0 && map[i] != '1')
			return (0);
		if (lines == l_map->y)
		{
			i++;
			while (map[i])
			{
				if (map[i]!= '1')
					return (0);
				i++;
			}
			i--;
		}
		i++;
	}
	return (1);
}

void double_free(char **map_split, t_map *l_map)
{
	int	i;

	i = 0;
	while (i < l_map->y + 1)
	{
		free(map_split[i]);
		i++;
	}
	free(map_split);
	return;
}

int map_line(char *map, t_map *l_map)
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

int map_valid(t_map *l_map)
{
	if (l_map->c >= 1 && l_map->p >= 1 && l_map->e >= 1 &&
		l_map->x >= 1 &&l_map->y >= 1)
		return (1);
	else
		return (0);
}

int	checkmap(char *map, int *width, int *height)
{
	t_map l_map;

	map_init(&l_map);
	if (!(map_char(map, &l_map)) || !(map_wall(map, &l_map)) || !(map_line(map, &l_map)) || !(map_valid(&l_map)))
		return (0);
	*width = l_map.x;
	*height = l_map.y + 1;
	return (1);
}

char	*ft_map_to_string(char *map)
{
	int fd;
	char *str;
	char *tmp;
	int rt;
	char buffer[2];

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