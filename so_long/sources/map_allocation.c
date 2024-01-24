/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:12:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:48 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_last_line(char **map_array, int linecount)
{
	int	i;

	i = 0;
	while(map_array[linecount - 1][i] != 0)
	{
		if (map_array[linecount - 1][i] != 1)
		{
			ft_free_pointer_array(map_array);
			ft_printf("Map is not functional\n");			
			exit(EXIT_FAILURE);
		} 
		i++;
	}
}

void	make_map_array(int fd, int linecount)
{
	char	**map_array;
	int		i;
	
	i = 0;
	map_array = malloc((linecount + 1) * sizeof(char *));
	if (map_array == 0)
		exit (EXIT_FAILURE);
	while (map_array[i] != 0)
	{		
		map_array[i] = get_next_line(fd);
		i++;		
	}
	map_array[i] = 0;
	check_last_line(map_array, linecount);
}

