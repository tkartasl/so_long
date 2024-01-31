/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:23:03 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/31 12:48:27 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_image_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'P')	
			{
				if (mlx_image_to_window(data->mlx, data->player,
						IMG * x, IMG * y) < 0)
					ft_error(data->map);
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
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'E')	
			{
				if (mlx_image_to_window(data->mlx, data->exit,
						IMG * x, IMG * y) < 0)
					ft_error(data->map);
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
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == '1')
			{
				if (mlx_image_to_window(data->mlx, data->wall,
						IMG * x, IMG * y) < 0)
					ft_error(data->map);
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
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == 'C')
			{
				if (mlx_image_to_window(data->mlx, data->pizza,
						IMG * x, IMG * y) < 0)
					ft_error(data->map);	
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
	while (data->map[y] != 0)
	{
		while (data->map[y][x] != 0 && data->map[y][x] != '\n')
		{
			if (data->map[y][x] != '1')
			{
				if (mlx_image_to_window(data->mlx, data->wall,
						IMG * x, IMG * y) < 0)
					ft_error(data->map);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
