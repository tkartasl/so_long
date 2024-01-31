/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:10:04 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/31 12:51:46 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map_size(char **map)
{
		ft_printf("Error\nMap doesn't properly fit to the screen");
		ft_free_pointer_array(map);
		exit(EXIT_FAILURE);
}

void ft_error(char **map)
{
	ft_free_pointer_array(map);
    ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
    exit(EXIT_FAILURE);
}

void	map_error(char	*str, int flag)
{
	char	*errors[3]= {"Map has incorrect shape",
			"Map not completely surrounded by walls",
			"Incorrect character inside the map"};
	ft_printf("Error\n%s\n", errors[flag]);
	free(str);
	str = 0;
	exit (EXIT_FAILURE);
}

void	item_error(char *line, int *ptr)
{
	if (ptr[0] < 1)
		ft_printf("Error\nNot enough collectibles\n");		
	if (ptr[1] < 1)
		ft_printf("Error\nNo exit found\n");
	if (ptr[1] > 1)
		ft_printf("Error\nToo many exits\n");
	if (ptr[2] < 1)
		ft_printf("Error\nNo player found\n");
	if (ptr[2] > 1)
		ft_printf("Error\nToo many players\n");
	ptr = 0;
	free(line);
	line = 0;
	exit(EXIT_FAILURE);
}
