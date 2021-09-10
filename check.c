/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:20:34 by wollio            #+#    #+#             */
/*   Updated: 2021/09/10 11:43:36 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if there is wall at the bottom */
int	walls_down(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->wallsmax)
	{
		if (win->y + 1 == win->walls[i][0] && win->x == win->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

/* Check if there is wall on the right */
int	walls_right(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->wallsmax)
	{
		if (win->y == win->walls[i][0] && win->x + 1 == win->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

/* Check if there is wall on the left */
int	walls_left(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->wallsmax)
	{
		if (win->y == win->walls[i][0] && win->x - 1 == win->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

/* Check if there is wall at the top */
int	walls_up(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->wallsmax)
	{
		if (win->y - 1 == win->walls[i][0] && win->x == win->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

/* Manage the collectables */
int	collect(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->collectmax)
	{
		if (win->y == win->collects[i][0]
			&& win->x == win->collects[i][1])
		{
			win->collects[i][0] = -1;
			win->collects[i][1] = -1;
			return (1);
		}
		i++;
	}
	return (0);
}