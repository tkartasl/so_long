/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:12:14 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/29 16:28:50 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_to_image(mlx_t *mlx, t_images *img, t_textures *texture)
{
	img->collectible = mlx_texture_to_image(mlx, texture->pizza);	
	if (img->collectible == 0)
		ft_error();
	img->exit = mlx_texture_to_image(mlx, texture->exit);	
	if (img->exit == 0)
		ft_error();	
	img->player = mlx_texture_to_image(mlx, texture->player);	
	if (img->player == 0)
		ft_error();
	img->wall = mlx_texture_to_image(mlx, texture->tree);	
	if (img->wall == 0)
		ft_error();
	img->floor = mlx_texture_to_image(mlx, texture->grass);	
	if (img->floor == 0)
		ft_error();
}

void	get_textures(mlx_t *mlx, t_images *img, t_textures *texture)
{
	texture->grass = mlx_load_png("../textures/grass.png");
	if (texture->grass == 0)
		ft_error();
	texture->pizza = mlx_load_png("../textures/pizza.png");
	if (texture->pizza == 0)
		ft_error();
	texture->player = mlx_load_png("../textures/Necromancer.png");
	if (texture->player == 0)
		ft_error();
	texture->exit = mlx_load_png("../textures/Blackhole.png");
	if (texture->exit == 0)
		ft_error();
	texture->tree = mlx_load_png("../textures/tree.png");
	if (texture->tree == 0)
		ft_error();	
}


void	make_images(mlx_t *mlx, t_images *img)
{
	img->collectible = mlx_new_image(mlx, BLOCK, BLOCK);
	if (img->collectible == 0)
		ft_error();
	img->exit = mlx_new_image(mlx, BLOCK, BLOCK);
	if (img->exit == 0)
		ft_error();	
	img->floor = mlx_new_image(mlx, BLOCK, BLOCK);
	if (img->floor == 0)
		ft_error();
	img->player = mlx_new_image(mlx, BLOCK, BLOCK);
	if (img->player == 0)
		ft_error();
	img->wall = mlx_new_image(mlx, BLOCK, BLOCK);
	if (img->wall == 0)
		ft_error();
}

void	create_window(char **map, t_items *item, t_images *img, t_textures *tx)
{	
	mlx_t	*mlx;
	char	*title;

	title = "Best Game Ever!";
	mlx = mlx_init(item->width * BLOCK, item->height * BLOCK, title, true);
	if (mlx == 0)
		ft_error();
	make_images(img);
	get_textures(mlx, tx);
	texture_to_image(mlx, img, tx);
	build_map();
}

int	main(int argc, char *argv[])
{
	t_items		item;
	t_images	img;
	t_textures	texture;
	char		**map;
		
	if (argc != 2 || argv[1][0] == 0)
		return (0);
	map = map_check(argv[1], &item);
	ft_memset(&item, 0, sizeof(t_items));
	ft_memset(&img, 0, sizeof(t_images));
	create_window(map, &item, &img, &texture);

	return(EXIT_SUCCESS);
}
