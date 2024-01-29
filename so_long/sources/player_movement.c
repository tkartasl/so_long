/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:13 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/29 16:20:40 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_image_t	*image;

	image = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		image->instances[0].y -= 42;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		image->instances[0].y += 42;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		image->instances[0].x -= 42;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		image->instances[0].x += 42;
}