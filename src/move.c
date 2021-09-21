/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:16:44 by wollio            #+#    #+#             */
/*   Updated: 2021/09/21 12:12:57 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(0);
}

/* Handle the moves of the player */
void	move(int keycode, t_window *win)
{
	if (keycode == KEY_A && walls_left(win))
		move_left(win);
	if (keycode == KEY_D && walls_right(win))
		move_right(win);
	if (keycode == KEY_S && walls_down(win))
		move_down(win);
	if (keycode == KEY_W && walls_up(win))
		move_up(win);
}

/* Manage the moves of the figure and the modification done on the win */
int	key_hook(int keycode, t_window *win)
{
	move(keycode, win);
	if (collect(win))
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
			win->x * 32, win->y * 32);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
			win->x * 32, win->y * 32);
		win->banana--;
	}
	if (keycode == KEY_ESC || (win->banana == 0
			&& win->x == win->exitx && win->y == win->exity))
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	printf("Movement count: %d\n", win->mov);
	return (1);
}
