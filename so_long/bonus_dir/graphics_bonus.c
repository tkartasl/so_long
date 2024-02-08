/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:48:52 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/08 12:40:15 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	texture_to_image(t_data *data, t_textures *tx)
{
	data->pizza = mlx_texture_to_image(data->mlx, tx->pizza);
	mlx_delete_texture(tx->pizza);
	if (data->pizza == 0)
		ft_error(data);
	data->exit = mlx_texture_to_image(data->mlx, tx->exit);
	mlx_delete_texture(tx->exit);
	if (data->exit == 0)
		ft_error(data);
	data->player = mlx_texture_to_image(data->mlx, tx->player);
	mlx_delete_texture(tx->player);
	if (data->player == 0)
		ft_error(data);
	data->wall = mlx_texture_to_image(data->mlx, tx->tree);
	mlx_delete_texture(tx->tree);
	if (data->wall == 0)
		ft_error(data);
	data->floor = mlx_texture_to_image(data->mlx, tx->grass);
	mlx_delete_texture(tx->grass);
	if (data->floor == 0)
		ft_error(data);
}

static void	get_textures(t_data *data, t_textures *texture)
{
	texture->grass = mlx_load_png("textures/grass.png");
	if (texture->grass == 0)
		ft_error(data);
	texture->pizza = mlx_load_png("textures/pizza.png");
	if (texture->pizza == 0)
		ft_error(data);
	texture->player = mlx_load_png("textures/Dudemonster.png");
	if (texture->player == 0)
		ft_error(data);
	texture->exit = mlx_load_png("textures/Blackhole.png");
	if (texture->exit == 0)
		ft_error(data);
	texture->tree = mlx_load_png("textures/bush1.png");
	if (texture->tree == 0)
		ft_error(data);
}

static void	create_images(t_data *data)
{
	data->pizza = mlx_new_image(data->mlx, IMG, IMG);
	if (data->pizza == 0)
		ft_error(data);
	data->exit = mlx_new_image(data->mlx, IMG, IMG);
	if (data->exit == 0)
		ft_error(data);
	data->floor = mlx_new_image(data->mlx, IMG, IMG);
	if (data->floor == 0)
		ft_error(data);
	data->player = mlx_new_image(data->mlx, IMG, IMG);
	if (data->player == 0)
		ft_error(data);
	data->wall = mlx_new_image(data->mlx, IMG, IMG);
	if (data->wall == 0)
		ft_error(data);
}

void	movement_count_to_window(t_data *data, int key_press)
{
	char		*counter;
	static int	i;

	if (data->player->enabled == false)
		return ;
	if (i > 0)
		mlx_delete_image(data->mlx, data->count);
	counter = ft_itoa(key_press);
	data->count = mlx_put_string(data->mlx, counter, 0, 0);
	if (data->count == 0)
	{
		free(counter);
		ft_error(data);
	}
	free(counter);
	i++;
}

void	get_graphics(t_data *data, t_textures *tx)
{
	create_images(data);
	get_textures(data, tx);
	texture_to_image(data, tx);
	if (data->img_size > 0)
		resize_images(data);
	floor_image_to_map(data);
	wall_image_to_map(data);
	exit_image_to_map(data);
	player_image_to_map(data);
	pizza_image_to_map(data);
}
