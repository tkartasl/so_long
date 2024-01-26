/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:12:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/26 14:54:10 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != 0)
	{
		while (map[j][i] != 0)
		{
			if (map[j][i] == 'x')
				map[j][i] = '0';
			if (map[j][i] == 'c')
				map[j][i] = 'C';
			if (map[j][i] == 'e')
				map[j][i] = 'E';
			i++;	
		}
		i = 0;
		j++;
	}
}

void	find_player_position(char **map, t_items *item)
{
	int		row;
	int		column;
	
	row = 0;
	column = 0;
	while (map[row] != 0)
	{
		while (map[row][column] != 0)
		{
			if (map[row][column] == 'P')
			{
				item->p_pos_r = row;
				item->p_pos_c = column;
			}
			if (map[row][column] == 'C')
				item->c_count++;	
			column++;
		}
		column = 0;
		row++;	
	}
}

int	flood_fill(char **map, t_items *item, size_t lc, size_t row, size_t col)
{
	size_t		len;
	static int	collectibles;
	
	len = ft_strlen(map[0]);
	if (row < 0 || row >= lc || col < 0 || col >= len - 1)
		return (collectibles);
	if (map[row][col] == '1' || map[row][col] == 'x')
		return (collectibles);
	if (map[row][col] == '0')
		map[row][col] = 'x';
	if (map[row][col] == 'E')
	{
		item->exit++;
		map[row][col] = 'e';
	}	
	if (map[row][col] == 'C')
	{
		collectibles++;
		map[row][col] = 'c';
	}	
	collectibles = flood_fill(map, item, lc, row - 1, col);
	collectibles = flood_fill(map, item, lc, row + 1, col);
	collectibles = flood_fill(map, item, lc, row, col - 1);
	collectibles = flood_fill(map, item, lc, row, col + 1);
	return (collectibles);
}

void	validate_path(char **map, t_items *item, size_t linecount)
{
	size_t	row;
	size_t	col;
	int	collectibles;
	
	collectibles = 0;
	row = 0;
	col = 0;
	
	find_player_position(map, item);
	row = item->p_pos_r;
	col = item->p_pos_c;
	collectibles = flood_fill(map, item, linecount, row, col);
	if (collectibles != item->c_count || item->exit != 1)
	{
		ft_free_pointer_array(map);
		exit(EXIT_FAILURE);
	}
	clean_map(map);
}

char	**make_map_array(int fd, size_t linecount, t_items *item)
{
	char	**map;
	int		i;
	
	i = 0;
	map = malloc((linecount + 1) * sizeof(char *));
	if (map == 0)
		exit(EXIT_FAILURE);
	while (map[i] != 0)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	check_last_line(map, linecount);
	validate_path(map, item, linecount);
	return (map);
}