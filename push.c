/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:50:13 by wollio            #+#    #+#             */
/*   Updated: 2021/09/10 15:05:53 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_figure(t_window *win, t_counter *count)
{
	win->x = count->y;
	win->y = count->x;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure, count->y * 32, count->x * 32);
	return;
}

void	push_collect(t_window *win, t_counter *count)
{
	win->banana++;
	win->collects[count->j][0] = count->x;
	win->collects[count->j][1] = count->y;
	count->j++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->collect,
		count->y * 32, count->x * 32);
	return ;
}

void	push_exit(t_window *win, t_counter *count)
{
	win->exitx = count->y;
	win->exity = count->x;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->exit, count->y * 32, count->x * 32);
	return;
}

void	push_walls(t_window *win, t_counter *count)
{
	win->walls[count->t][0] = count->x;
	win->walls[count->t][1] = count->y;
	count->t++;
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->wall,
		count->y * 32, count->x * 32);
	return ;
}

void	push_items(char pos, t_window *win, t_counter *count)
{
	if (pos != '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->floor, count->y * 32, count->x * 32);
	if (pos == 'P' && win->x == -1 && win->y == -1)
		push_figure(win, count);
	else if (pos == 'C')
		push_collect(win, count);
	else if (pos == 'E' && win->exitx == -1 && win->exity == -1)
		push_exit(win, count);
	else if (pos == '1')
		push_walls(win, count);
	return;
}