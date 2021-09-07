/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:38:00 by wollio            #+#    #+#             */
/*   Updated: 2021/09/07 14:52:15 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialization of the windows struct */
void	init_windows(t_window *win, int width, int height)
{
	int img_width;
	int img_height;

	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, width * 32, height * 32, "Hello darling");
	win->floor = mlx_xpm_file_to_image(win->mlx,"./images/floor.xpm", &img_width, &img_height);
	win->figure = mlx_xpm_file_to_image(win->mlx,"./images/figure.xpm", &img_width, &img_height);
	win->collect = mlx_xpm_file_to_image(win->mlx,"./images/banana.xpm", &img_width, &img_height);
	win->wall = mlx_xpm_file_to_image(win->mlx,"./images/wall.xpm", &img_width, &img_height);
	win->exit = mlx_xpm_file_to_image(win->mlx,"./images/exit.xpm", &img_width, &img_height);
	win->banana = 0;
	win->steps = 0;
	win->height = height;
	win->width = width;
	win->x = -1;
	win->y = -1;
	win->exitx = -1;
	win->exity = -1;
	return;
}

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
	while (count.x < height)
	{
		count.y = 0;
		while (count.y < width)
		{
			push_images(map[count.i], &win, &count);
			count.y++;
			count.i++;
		}
		count.x++;
		count.i++;
	}
	mlx_loop(win.mlx);
	return;
}