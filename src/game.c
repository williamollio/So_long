/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:38:00 by wollio            #+#    #+#             */
/*   Updated: 2021/09/20 19:17:50 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Initialization of the window struct */
void	init_windows(t_window *win, int width, int height)
{
	int img_width;
	int img_height;

	win->banana = 0;
	win->mov = 0;
	win->height = height;
	win->width = width;
	win->x = -1;
	win->y = -1;
	win->exitx = -1;
	win->exity = -1;
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, width * 32, height * 32, "Hello darling");
	win->floor = mlx_xpm_file_to_image(win->mlx,"./images/floor.xpm", &img_width, &img_height);
	win->figure = mlx_xpm_file_to_image(win->mlx,"./images/figure.xpm", &img_width, &img_height);
	win->collect = mlx_xpm_file_to_image(win->mlx,"./images/banana.xpm", &img_width, &img_height);
	win->wall = mlx_xpm_file_to_image(win->mlx,"./images/wall.xpm", &img_width, &img_height);
	win->exit = mlx_xpm_file_to_image(win->mlx,"./images/exit.xpm", &img_width, &img_height);
}

/* Initialization of the counter struct */
void	init_counter(t_counter *count)
{
	count->i = 0;
	count->x = 0;
	count->y = 0;
	count->j = 0;
	count->t = 0;
}


/* Main function of the project */
void	ft_game(char *map, int width, int height)
{
	t_window	win;
	t_counter	count;

	init_windows(&win, width, height);
	init_counter(&count);
	while (count.y < height)
	{
		count.x = 0;
		while (count.x < width)
		{
			push_items(map[count.i], &win, &count);
			count.x++;
			count.i++;
		}
		count.y++;
		count.i++;
	}
	win.wallsmax = count.t;
	win.collectmax = count.j;
	mlx_key_hook(win.mlx_win, key_hook, &win);
	mlx_hook(win.mlx_win, 17, (1L << 17), close_window, &win);
	mlx_loop(win.mlx);
	return;
}