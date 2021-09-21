/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:49:05 by wollio            #+#    #+#             */
/*   Updated: 2021/09/21 11:50:25 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Initialization of the struct l_map */
void	map_init(t_map *l_map)
{
	l_map->c = 0;
	l_map->e = 0;
	l_map->p = 0;
	l_map->x = 0;
	l_map->y = 0;
}

/* Count the elements of the map */
int	map_char(char *map, t_map *l_map)
{
	int	i;

	i = 0;
	while (map[i])
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

/* Count the number of lines */
void	numberofline(char *map, t_map *l_map)
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
}

/* Verify the first and the last line */
int	first_and_last(char *map, t_map *l_map, size_t *k, int lines)
{
	size_t	i;

	i = *k;
	if (lines == 0 && map[i] != '1')
		return (0);
	else if (lines == l_map->y)
	{
		i++;
		while (map[i])
		{
			if (map[i] != '1')
				return (0);
			i++;
		}
		i--;
	}
	return (1);
}

/* Verify that the borders are composed of walls */
int	map_wall(char *map, t_map *l_map)
{
	size_t	i;
	int		lines;

	i = 0;
	lines = 0;
	numberofline(map, l_map);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			lines++;
			if (map[i - 1] != '1' || !((map[i + 1] == '1')
					|| (map[i + 1] == '\0')))
				return (0);
		}
		if (lines == 0 || lines == l_map->y)
		{
			if (!(first_and_last(map, l_map, &i, lines)))
				return (0);
		}
		i++;
	}
	return (1);
}
