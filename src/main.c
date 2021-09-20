/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:56:50 by wollio            #+#    #+#             */
/*   Updated: 2021/09/20 18:14:13 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	char	*map;
	int		width;
	int		height;

	if (argc != 2)
	{
		printf("Error\nThere is no map\n");
		return (0);
	}
	map = ft_map_to_string(argv[1]);
	if (!map)
	{
		printf("Error\nThe map can't be read somehow\n");
		return (0);
	}
	if (checkmap(map, &width, &height) == 0)
	{
		printf("Error\nThere is a problem with your map\n");
		free(map);
		return (0);
	}
	ft_game(map, width, height);
	free(map);
	return (0);
}