/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:50:13 by wollio            #+#    #+#             */
/*   Updated: 2021/09/21 11:26:46 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	push_figure(t_window *win, t_counter *count)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->figure,
		count->x * 32, count->y * 32);
	win->y = count->y;
	win->x = count->x;
}

void	push_collect(t_window *win, t_counter *count)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->collect,
		count->x * 32, count->y * 32);
	win->banana++;
	win->collects[count->j][0] = count->y;
	win->collects[count->j][1] = count->x;
	count->j++;
}

void	push_exit(t_window *win, t_counter *count)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->exit,
		count->x * 32, count->y * 32);
	win->exity = count->y;
	win->exitx = count->x;
}

void	push_walls(t_window *win, t_counter *count)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->wall,
		count->x * 32, count->y * 32);
	win->walls[count->t][0] = count->y;
	win->walls[count->t][1] = count->x;
	count->t++;
}

void	push_items(char pos, t_window *win, t_counter *count)
{
	if (pos != '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->floor, count->x * 32, count->y * 32);
	if (pos == 'P' && win->y == -1)
		push_figure(win, count);
	else if (pos == 'C')
		push_collect(win, count);
	else if (pos == 'E' && win->exity == -1)
		push_exit(win, count);
	else if (pos == '1')
		push_walls(win, count);
}
