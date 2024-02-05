/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:48:52 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/05 16:04:39 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(t_data *data, t_textures *tx)
{
	data->pizza = mlx_texture_to_image(data->mlx, tx->pizza);	
	if (data->pizza == 0)
		ft_error(data);
	data->exit = mlx_texture_to_image(data->mlx, tx->exit);	
	if (data->exit == 0)
		ft_error(data);	
	data->player = mlx_texture_to_image(data->mlx, tx->player);	
	if (data->player == 0)
		ft_error(data);
	data->wall = mlx_texture_to_image(data->mlx, tx->tree);	
	if (data->wall == 0)
		ft_error(data);
	data->floor = mlx_texture_to_image(data->mlx, tx->grass);	
	if (data->floor == 0)
		ft_error(data);
}

void	get_textures(t_data *data, t_textures *texture)
{
	texture->grass = mlx_load_png("../textures/grass.png");
	if (texture->grass == 0)
		ft_error(data);
	texture->pizza = mlx_load_png("../textures/pizza.png");
	if (texture->pizza == 0)
		ft_error(data);
	texture->player = mlx_load_png("../textures/Dudemonster.png");
	if (texture->player == 0)
		ft_error(data);
	texture->exit = mlx_load_png("../textures/Blackhole.png");
	if (texture->exit == 0)
		ft_error(data);
	texture->tree = mlx_load_png("../textures/bush1.png");
	if (texture->tree == 0)
		ft_error(data);
}

void	create_images(t_data *data)
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
