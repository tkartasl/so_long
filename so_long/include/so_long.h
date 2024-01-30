/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:16:44 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/30 16:17:23 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef IMG
# 	define IMG 50
# endif
# include "../libft/libft.h"
# include "../../../MLX42/include/MLX42/MLX42.h"

typedef struct s_items
{
	int		c_count;
	int		exit;
	int 	p_pos_r;
	int		p_pos_c;
	size_t	width;
	size_t	height;
}		t_items;

typedef	struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*pizza;
	t_items		*info;
	char		**map;
}		t_data;

typedef	struct s_textures
{
	mlx_texture_t	*grass;
	mlx_texture_t	*pizza;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*tree;
}		t_textures;
#endif