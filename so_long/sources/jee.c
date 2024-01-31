#include "so_long.h"

void	clean_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j] != 0)
	{
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == 'x')
				data->map[j][i] = '0';
			if (data->map[j][i] == 'c')
				data->map[j][i] = 'C';
			if (data->map[j][i] == 'e')
				data->map[j][i] = 'E';
			i++;
		}
		i = 0;
		j++;
	}
}

void	find_player_position(t_data *data)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (data->map[row] != 0)
	{
		while (data->map[row][column] != 0)
		{
			if (data->map[row][column] == 'P')
			{
				data->info->p_pos_r = row;
				data->info->p_pos_c = column;
			}
			if (data->map[row][column] == 'C')
				data->info->c_count++;
			column++;
		}
		column = 0;
		row++;
	}
}

int	flood_fill(t_data *data, size_t lc, size_t row, size_t col)
{
	size_t	len;
	static int	collectibles;

	len = ft_strlen(data->map[0]);
	if (row < 0 || row >= lc || col < 0 || col >= len - 1)
		return (collectibles);
	if (data->map[row][col] == '1' || data->map[row][col] == 'x')
		return (collectibles);
	if (data->map[row][col] == '0')
		data->map[row][col] = 'x';
	if (data->map[row][col] == 'E')
	{
		data->info->exit++;
		data->map[row][col] = 'e';
	}
	if (data->map[row][col] == 'C')
	{
		collectibles++;
		data->map[row][col] = 'c';
	}
	collectibles = flood_fill(data, lc, row - 1, col);
	collectibles = flood_fill(data, lc, row + 1, col);
	collectibles = flood_fill(data, lc, row, col - 1);
	collectibles = flood_fill(data, lc, row, col + 1);
	return (collectibles);
}

void	validate_path(t_data *data, size_t linecount)
{
	size_t	row;
	size_t	col;
	int	collectibles;

	collectibles = 0;
	row = 0;
	col = 0;

	find_player_position(data);
	row = data->info->p_pos_r;
	col = data->info->p_pos_c;
	collectibles = flood_fill(data, linecount, row, col);
	if (collectibles != data->info->c_count || data->info->exit != 1)
	{
		ft_printf("Error\nNo valid path on the map");
		ft_free_pointer_array(data->map);
		exit(EXIT_FAILURE);
	}
	clean_map(data);
}

void	make_map_array(int fd, size_t linecount, t_data *data)
{
	int	i;

	i = 0;
	data->map = malloc((linecount + 1) * sizeof(char *));
	if (data->map == 0)
		exit(EXIT_FAILURE);
	data->map[linecount + 1] = 0;
	while (data->map[i] != 0)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	data->info->height = linecount;
	data->info->width = ft_strlen(data->map[0]) - 1;
	check_last_line(data->map, linecount);
	validate_path(data, linecount);
}