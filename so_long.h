/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:07:09 by wollio            #+#    #+#             */
/*   Updated: 2021/09/07 14:54:25 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description

MiniLibX is an easy way to create graphical software, without any X-Window/Cocoa programming knowledge.
It provides simple window creation, a drawing tool, image and basic events management.
*/

#ifndef SO_LONG
# define SO_LONG

/* Keycodes */
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15

/* Include my libft, the minilibx library and the some others librairies */
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

/* Struct made for checking the format of the map in input */
typedef struct	map
{
	int	c;
	int	e;
	int	p;
	int	x;
	int	y;
}				t_map;

/* Struct made for creating the map of the game */
typedef struct window
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*figure;
	void	*collect;
	void	*wall;
	void	*exit;
	int		banana;
	int		steps;
	int		height;
	int		width;
	int		x; // pos of figure
	int		y; // pos of figure
	int		exitx;
	int		exity;
	int		collects[100][2];
	int		wallsmax; // number walls
	int		collectmax; // number collectables
	int		walls[1000][2];

}				t_window;

/* Struct made to keep track of movements by the player*/
typedef struct s_counter
{
	int	i;
	int	x;
	int	y;
	int	j; // count collectables
	int	t; // count walls
}				t_counter;


int		main(int argc, char *argv[]);

/* Read map and check for validity */
char	*ft_map_to_string(char *map);
void	map_init(t_map *l_map);
int		map_char(char *map, t_map *l_map);
void	numberofline(char *map, t_map *l_map);
int		map_wall(char *map, t_map *l_map);
void	double_free(char **map_split, t_map *l_map);
int		map_line(char *map, t_map *l_map);
int		map_valid(t_map *l_map);
int		checkmap(char *map, int *width, int *height);

/* Creation map of the game */
void	ft_game(char *map, int width, int height);
void init_windows(t_windows *win, int width, int height);
void	init_counter(t_counter *count);

/* Push the items on the window */
void	push_images(char pos, t_windows win, t_counter count);


/*
Copyrights images

All the graphic tiles used in this program is the public domain roguelike tileset "RLTiles".
Some of the tiles have been modified by me.

You can find the original tileset at:
http://rltiles.sf.net */

/* */

#endif