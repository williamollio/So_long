/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:16:44 by wollio            #+#    #+#             */
/*   Updated: 2021/09/10 11:20:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void)
{
	exit(0);
}

int	move_down(t_window *win)
{
	if (win->banana > 0 && win->y + 1 == win->exity && win->x == win->exitx)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->y++;
	win->steps++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	return (1);
}

int	move_right(t_window *win)
{
	if (win->banana > 0 && win->x + 1 == win->exitx && win->y == win->exity)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->x++;
	win->steps++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	return (1);
}

int	move_left(t_window *win)
{
	if (win->banana > 0 && win->x - 1 == win->exitx && win->y == win->exity)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->x--;
	win->steps++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	return (1);
}

int	move_up(t_window *win)
{
	if (win->banana > 0 && win->y - 1 == win->exity && win->x == win->exitx)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->y--;
	win->steps++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	return (1);
}

/* Manage the moves of the figure and the modification done on the win */
int	key_hook(int keycode, t_window *win)
{
	if ((win->banana == 0 && win->x == win->exitx
			&& win->y == win->exity) || keycode == KEY_ESC)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	if (keycode == KEY_S && walls_down(win) == 1)
		move_down(win);
	if (keycode == KEY_D && walls_right(win) == 1)
		move_right(win);
	if (keycode == KEY_A && walls_left(win) == 1)
		move_left(win);
	if (keycode == KEY_W && walls_up(win) == 1)
		move_up(win);
	if (collect(win) == 1 && win->banana > 0)
	{
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
			win->x * 32, win->y * 32);
		mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
			win->x * 32, win->y * 32);
		win->banana--;
	}
	printf("NUMBER OF MOVES: %d\n", win->steps);
	return (1);
}
