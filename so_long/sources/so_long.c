/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/26 10:26:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_key_hook(void *param, mlx_image_t *image)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{	
		mlx_close_window(param);
		mlx_terminate(mlx);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(param, MLX_KEY_W))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_S))
		image->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_A))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_D))
		image->instances[0].x += 5;
}

int32_t	main(int argc, char *argv[])
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*texture;
	char			**map;
	
	if (argc != 2 || argv[1][0] == 0)
		return (0);
	map = map_check(argv[1]);
	mlx = mlx_init(WIDTH, HEIGHT, "Best game ever", true);
	if (mlx == 0)
		error_handler();
	texture = mlx_load_png("../textures/");
	if (texture == 0)
		error_handler();
	image = mlx_texture_to_image(mlx, texture);
	if (image == 0)
		error_handler();
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
		error_handler();
	mlx_key_hook(mlx, &my_key_hook, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return(EXIT_SUCCESS);
}

