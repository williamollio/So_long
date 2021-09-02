/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:07:09 by wollio            #+#    #+#             */
/*   Updated: 2021/09/02 11:13:35 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>

typedef struct	map
{
	int c;
	int e;
	int p;
	int x;
	int y;
}				t_map;

int		main(int argc, char *argv[]);

// MAP
char	*ft_map_to_string(char *map);

#endif