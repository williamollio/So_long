/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:56:50 by wollio            #+#    #+#             */
/*   Updated: 2021/09/02 11:58:13 by wollio           ###   ########.fr       */
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

int firstcheck(char *map, t_map *l_map)
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


int	checkmap(char *map, int *width, int *height)
{
	t_map l_map;
	width = 0;
	height = 0;

	map_init(&l_map);
	if (firstcheck(map, &l_map) == 1)
	{
		printf("firstcheck is ok\n");
		return 1;
	}
	else
	{
		printf("firstcheck isn't ok\n");
		return 0;
	}

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