/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/08 12:40:28 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	resize_images(t_data *data)
{
	if (mlx_resize_image(data->exit, data->img_size, data->img_size) == false)
		ft_error(data);
	if (mlx_resize_image(data->player, data->img_size,
			data->img_size) == false)
		ft_error(data);
	if (mlx_resize_image(data->floor, data->img_size, data->img_size) == false)
		ft_error(data);
	if (mlx_resize_image(data->wall, data->img_size, data->img_size) == false)
		ft_error(data);
	if (mlx_resize_image(data->pizza, data->img_size, data->img_size) == false)
		ft_error(data);
}

static int	resize_window(t_data *data, int width, int height)
{
	unsigned int	new_size;
	int				window_width;
	int				window_height;

	if (data->info->height * IMG > (size_t)height)
		new_size = height / data->info->height;
	else
		new_size = width / data->info->width;
	if (data->info->height >= 82)
		new_size -= 1;
	window_width = data->info->width * new_size;
	window_height = data->info->height * new_size;
	mlx_set_window_size(data->mlx, window_width, window_height);
	return (new_size);
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
			data->info->height * IMG, title, false);
	if (data->mlx == 0)
		ft_error(data);
	mlx_set_window_limit(data->mlx, -1, -1, width, height);
	mlx_get_monitor_size(0, &width, &height);
	if (data->info->width * IMG > (size_t)width
		|| data->info->height * IMG > (size_t)height)
		data->img_size = resize_window(data, width, height);
	get_graphics(data, tx);
	mlx_key_hook(data->mlx, &my_key_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	ft_free_pointer_array(data->map);
}

static void	check_file_format(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		ft_printf("Error\nInvalid map format\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(".ber", &filename[len - 4], 4) != 0)
	{
		ft_printf("Error\nInvalid map format\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_items		item;
	t_data		data;
	t_textures	texture;

	if (argc != 2)
	{
		ft_printf("Error\nWrong amount of arguments\n");
		return (1);
	}
	ft_memset(&item, 0, sizeof(t_items));
	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&texture, 0, sizeof(t_textures));
	check_file_format(argv[1]);
	data.map = map_check(argv[1], &item);
	data.info = &item;
	if (data.info->height > 100 || data.info->width > 150)
	{
		ft_free_pointer_array(data.map);
		ft_printf("Error\nMap is too big\n");
		exit(EXIT_FAILURE);
	}
	create_window(&data, &texture);
	return (EXIT_SUCCESS);
}
