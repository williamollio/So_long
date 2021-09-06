/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:56:50 by wollio            #+#    #+#             */
/*   Updated: 2021/09/06 15:20:24 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*map;
	int		width;
	int		height;

	if (argc != 2)
	{
		printf("There is no map bro\n");
		return (0);
	}
	map = ft_map_to_string(argv[1]);
	if (!map)
	{
		printf("The map can't be read somehow alta\n");
		return (0);
	}
	if (checkmap(map, &width, &height) == 0)
	{
		printf("There is a problem with your map digga\n");
		free(map);
		return (0);
	}

	free(map);
	return (0);
}