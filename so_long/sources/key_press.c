/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:13 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/30 17:50:27 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_finished(t_data *data)
{
	char	*success;

	success = "Congratulations!!!"
	if (data->info->c_count == 0)	
	{
		data->player->enabled = false;
		
	}
	
}

void	disable_img_instance(t_data *data)
{
	int	i;

	i = 0;
	while (data->pizza->instances[i].x != x
				|| data->pizza->instances[i].y != y)
			i++;
	data->pizza->instances->enabled = false;
	data->info->c_count--;		
}

void	move_player(t_data *data, char key)
{
	static int	x;
	static int	y;
	static int	key_press_count;

	x = data->info->p_pos_c;
	y = data->info->p_pos_r;
	if (key == 'W' && data->map[y + 1][x] != '1')
		data->player->instances[0].y -= 50;
	if (key == 'S' && data->map[y - 1][x] != '1')
		data->player->instances[0].y += 50;
	if (key == 'A' && data->map[y][x - 1] != '1')
		data->player->instances[0].x -= 50;
	if (key == 'D' && data->map[y][x + 1] != '1')
		data->player->instances[0].x += 50;
	if (data->map[y][x] == 'C')
		disable_img_instance(data);
	if (data->map[y][x] == 'E')
		check_if_finished(data);
	key_press_count++;
	ft_printf("Movement count: %d\n", key_press_count);	
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(data, 'W');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(data, 'S');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(data, 'A');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(data, 'D');
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}
