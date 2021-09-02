/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:41:47 by wollio            #+#    #+#             */
/*   Updated: 2021/09/02 10:51:14 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "solong.h"
// #include "./minilibx/mlx.h"

// char	*ft_map_to_string(char *map)
// {
// 	int fd;
// 	char *str;
// 	char *tmp;
// 	int rt;
// 	char buffer[2];

// 	fd = open(map, O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	rt = read(fd, buffer, 1);
// 	while (rt)
// 	{
// 		buffer[rt] = '\0';
// 		if (!str)
// 			str = ft_strdup(buffer);
// 		else
// 		{
// 			tmp = ft_strjoin(str, buffer);
// 			free(str);
// 			str = tmp;
// 		}
// 		rt = read(fd, buffer, 1);
// 	}
// 	return (str);
// }