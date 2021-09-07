/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:50:13 by wollio            #+#    #+#             */
/*   Updated: 2021/09/07 14:56:05 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_figure(t_window *win, t_counter *count)
{
	win->x = count->x;
	win->y = count->y;

}
void	push_images(char pos, t_window *win, t_counter *count)
{
	if (pos != '1')
		mlx_put_image_to_window(win->mlx, win->mlx_win,
			win->floor, count->y * 32, count->x * 32);
	if (pos == 'P' && win->x == -1 && win->y == -1)
		push_figure(win, count);

}