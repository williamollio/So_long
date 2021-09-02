/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:56:50 by wollio            #+#    #+#             */
/*   Updated: 2021/09/02 15:45:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
	int i;

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
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if(map[i] == '\n')
			l_map->y++;
		i++;
	}
	return;
}
int	map_wall(char *map, t_map *l_map)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	numberofline(map, l_map);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			lines++;
			if (map[i-1] != '1' || !((map[i+1] == '1') || (map[i+1] == '\0')))
			{
			printf("i2 : %d\n", i);
			return (0);
			}
		}
		if (lines == 0 && map[i] != '1')
		{
			printf("i1 : %d\n", i);
			return (0);
		}
		if (lines == l_map->y)
		{
			i++;
			while(map[i])
			{
				if (map[i]!= '1')
				{
					printf("i3 : %d\n", i);
					return (0);
				}
				i++;
			}
			i--;
		}
		i++;
	}
	return (1);
}

int map_line(char *map, t_map *l_map)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			j = i;
			i++;
			while(map[i] != '\n')
				i++;
			x = i - j;
		}
		if (x != j)
			return (0);
		i++;
	}
	return (1);
}
int	checkmap(char *map, int *width, int *height)
{
	t_map l_map;


	map_init(&l_map);
	if (map_char(map, &l_map) && map_wall(map, &l_map) && map_line(map, &l_map))
	{
		printf("firstcheck && map_walls && map_line are fine\n");
		return (1);
	}
	*width = 0;
	*height = l_map.y + 1;
	return 0;

}
int	main(int argc, char *argv[])
{
	char	*map;
	int		width;
	int		height;

	if (argc != 2)
		printf("There is no map bro\n");
	map = ft_map_to_string(argv[1]);
	if (!map)
		printf("The map can't be read somehow alta\n");
	if (checkmap(map, &width, &height) == 0)
		printf("There is a problem with your map digga\n");
	return 0;
}