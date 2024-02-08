/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:16:44 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/08 12:34:08 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef IMG
#  define IMG 50
# endif
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_items
{
	int		c_count;
	int		exit;
	int		p_pos_r;
	int		p_pos_c;
	size_t	width;
	size_t	height;
}		t_items;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*pizza;
	mlx_image_t	*count;
	t_items		*info;
	char		**map;
	int			img_size;
}		t_data;

typedef struct s_textures
{
	mlx_texture_t	*grass;
	mlx_texture_t	*pizza;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*tree;
}		t_textures;

void	item_error(char *line, int *ptr);
void	map_error(char	*str, int flag);
void	ft_error(t_data *data);
void	error_map_size(char **map);
char	**map_check(char *filename, t_items *item);
char	**make_map_array(char *filename, size_t linecount, t_items *item);
void	get_graphics(t_data *data, t_textures *tx);
void	resize_images(t_data *data);
void	floor_image_to_map(t_data *data);
void	pizza_image_to_map(t_data *data);
void	wall_image_to_map(t_data *data);
void	exit_image_to_map(t_data *data);
void	player_image_to_map(t_data *data);
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	check_last_line(char **map, size_t linecount);
void	movement_count_to_window(t_data *data, int key_press);

#endif