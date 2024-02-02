/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/02 15:16:16 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_resize_hook(int width, int height, void *param)
{
	t_data	*data;

	data = param;
	
}

static	void	get_graphics(t_data *data, t_textures *tx)
{
	int	i;

	i = 0;
	create_images(data);
	get_textures(data, tx);
	texture_to_image(data, tx);
	floor_image_to_map(data);
	wall_image_to_map(data);
	exit_image_to_map(data);
	player_image_to_map(data);
	pizza_image_to_map(data);	
}


static	void	create_window(t_data *data, t_textures *tx)
{	
	char	*title;
	int		width;
	int		height;
	
	width = 0;
	height = 0;
	title = "Best Game Ever!";
	data->mlx = mlx_init(data->info->width * IMG,
			data->info->height * IMG, title, true);
	if (data->mlx == 0)
		ft_error(data->map);
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_limit(data->mlx, -1, -1, width, height);
	//if (item->width > width || item->height > height)
		//error_map_size(map);
	get_graphics(data, tx);
	mlx_key_hook(data->mlx, &my_key_hook, data);
	mlx_resize_hook(data->mlx, &my_resize_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	ft_free_pointer_array(data->map);
}

int	main(int argc, char *argv[])
{
	t_items		item;
	t_data		data;
	t_textures	texture;
	
	if (argc != 2)
	{
		ft_printf("Error\nWrong amount of arguments");
		return (1);
	}
	ft_memset(&item, 0, sizeof(t_items));
	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&texture, 0, sizeof(t_textures));
	data.map = map_check(argv[1], &item);
	data.info = &item;
	create_window(&data, &texture);
	return(EXIT_SUCCESS);
}
