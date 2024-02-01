/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:13 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/01 16:31:42 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	check_if_finished(t_data *data)
{
	char		*success;
	mlx_image_t	*image;

	image = 0;
	success = "CONGRATULATIONS, YOU ARE AMAZING!!!";
	if (data->info->c_count == 0)
	{
		data->player->enabled = false;
		image = mlx_put_string(data->mlx, success, 0, 0);
		if (image == 0)
			ft_error(data->map);
	}
}

static	void	remove_collectable(t_data *data, int x , int y)
{
	int	i;

	i = 0;
	ft_printf("instance: %p", data->pizza->instances);
	while (data->pizza->instances[i].x != x
			|| data->pizza->instances[i].y != y)
			i++;
	data->pizza->instances->enabled = false;
	data->map[y][x] = '0';
	data->info->c_count--;		
}


static int	check_if_player_can_move(int x, int y, t_data *data, char key)
{
	if (key == 'W' && data->map[y][x] == '1')
	{
		data->info->p_pos_r += 1;
		return (1);
	}
	if (key == 'S' && data->map[y][x] == '1')
	{
		data->info->p_pos_r -= 1;
		return (1);
	}
	if (key == 'A' && data->map[y][x] == '1')
	{
		data->info->p_pos_c += 1;
		return (1);
	}
	if (key == 'D' && data->map[y][x] == '1')
	{
		data->info->p_pos_c -= 1;
		return (1);
	}
	return (0);
}

static	void	move_player(t_data *data, char key)
{
	int			x;
	int			y;
	static int	key_press_count;

	x = data->info->p_pos_c;
	y = data->info->p_pos_r;
	if (check_if_player_can_move(x, y, data, key) == 1)
		return ;
	ft_printf("x: %d, y: %d\n", x, y);
	if (key == 'W' && data->map[y][x] != '1')
		data->player->instances[0].y -= 50;
	if (key == 'S' && data->map[y][x] != '1')
		data->player->instances[0].y += 50;
	if (key == 'A' && data->map[y][x] != '1')
		data->player->instances[0].x -= 50;
	if (key == 'D' && data->map[y][x] != '1')
		data->player->instances[0].x += 50;
	if (data->map[y][x] == 'C')
		remove_collectable(data, x, y);
	if (data->map[y][x] == 'E')
		check_if_finished(data);
	key_press_count++;
	//ft_printf("Movement count: %d\n", key_press_count);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	
	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		data->info->p_pos_r -= 1;
		move_player(data, 'W');
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		data->info->p_pos_r += 1;
		move_player(data, 'S');
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		data->info->p_pos_c -= 1;
		move_player(data, 'A');
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		data->info->p_pos_c += 1;
		move_player(data, 'D');
	}	
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}
