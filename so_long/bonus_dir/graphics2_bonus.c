/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/07 13:20:15 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_size == 0)
		data->img_size = IMG;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (y == data->info->p_pos_r && x == data->info->p_pos_c)
			{
				if (mlx_image_to_window(data->mlx, data->player,
						data->img_size * x, data->img_size * y) < 0)
					ft_error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	exit_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_size == 0)
		data->img_size = IMG;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'E')
			{
				if (mlx_image_to_window(data->mlx, data->exit,
						data->img_size * x, data->img_size * y) < 0)
					ft_error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	wall_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_size == 0)
		data->img_size = IMG;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == '1')
			{
				if (mlx_image_to_window(data->mlx, data->wall,
						data->img_size * x, data->img_size * y) < 0)
					ft_error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	pizza_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_size == 0)
		data->img_size = IMG;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
			{
				if (mlx_image_to_window(data->mlx, data->pizza,
						data->img_size * x, data->img_size * y) < 0)
					ft_error(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	floor_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (data->img_size == 0)
		data->img_size = IMG;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (mlx_image_to_window(data->mlx, data->floor,
					data->img_size * x, data->img_size * y) < 0)
				ft_error(data);
			x++;
		}
		x = 0;
		y++;
	}
}
