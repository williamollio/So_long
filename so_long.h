/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:07:09 by wollio            #+#    #+#             */
/*   Updated: 2021/09/06 15:12:53 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

typedef struct	map
{
	int	c;
	int	e;
	int	p;
	int	x;
	int	y;
}				t_map;

int		main(int argc, char *argv[]);

// Read map and check for validity
char	*ft_map_to_string(char *map);
void	map_init(t_map *l_map);
int		map_char(char *map, t_map *l_map);
void	numberofline(char *map, t_map *l_map);
int		map_wall(char *map, t_map *l_map);
void	double_free(char **map_split, t_map *l_map);
int		map_line(char *map, t_map *l_map);
int		map_valid(t_map *l_map);
int		checkmap(char *map, int *width, int *height);


#endif