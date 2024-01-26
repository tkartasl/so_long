/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:16:44 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/26 09:22:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 512
# define HEIGHT 512
# include "../libft/libft.h"
# include "../../MLX42/include/MLX42/MLX42.h"

typedef struct s_items
{
	int	c_count;
	int	exit;
	int p_pos_r;
	int	p_pos_c;
}		t_items;		
#endif