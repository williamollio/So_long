/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:22:07 by wollio            #+#    #+#             */
/*   Updated: 2021/09/02 10:32:27 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "./minilibx/mlx.h"

//int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*path;
	int		height;
	int		width;
	void	*img;

	printf("That's fine test");
	path = "./image/3_ghost.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 150, 150);
	mlx_loop(mlx);
	return 0;
}