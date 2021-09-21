/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:24:24 by wollio            #+#    #+#             */
/*   Updated: 2021/09/21 11:25:08 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_left(t_window *win)
{
	if (win->banana > 0 && win->x - 1 == win->exitx && win->y == win->exity)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->x--;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	win->mov++;
	return (1);
}

int	move_right(t_window *win)
{
	if (win->banana > 0 && win->x + 1 == win->exitx && win->y == win->exity)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->x++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	win->mov++;
	return (1);
}

int	move_down(t_window *win)
{
	if (win->banana > 0 && win->y + 1 == win->exity && win->x == win->exitx)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->y++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	win->mov++;
	return (1);
}

int	move_up(t_window *win)
{
	if (win->banana > 0 && win->y - 1 == win->exity && win->x == win->exitx)
		return (0);
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->floor,
		win->x * 32, win->y * 32);
	win->y--;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		win->x * 32, win->y * 32);
	win->mov++;
	return (1);
}
