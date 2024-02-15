/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:02:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/02/13 10:06:16 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_last_line(char **map, size_t linecount)
{
	int	i;

	i = 0;
	while (map[linecount - 1][i] != 0)
	{
		if (map[linecount - 1][i] != '1')
		{
			ft_free_pointer_array(map);
			ft_printf("Error\nMap not completely surrounded by walls");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static size_t	check_first_line(char *line)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(line);
	if (len <= 2)
		map_error(line, 3);
	while (line[i] != 0 && line[i] != '\n')
	{
		if (line[i] != '1')
			map_error(line, 1);
		i++;
	}
	return (len);
}

static int	*line_check(char *line, size_t len)
{
	size_t		i;
	static int	items[] = {0, 0, 0};

	if (line == 0)
		return (items);
	i = 0;
	while (line[i] != 0 && line[i] != '\n')
	{
		if (line[i] == 'C')
			items[0] += 1;
		if (line[i] == 'E')
			items[1] += 1;
		if (line[i] == 'P')
			items[2] += 1;
		if (ft_strchr("01PCE", line[i]) == 0)
			map_error(line, 2);
		i++;
	}
	if (i != len - 1)
		map_error(line, 0);
	if (line[0] != '1' || line[i - 1] != '1')
		map_error(line, 1);
	return (items);
}

static void	iterate_map(int fd, size_t *linecount, char *line, size_t len)
{
	int	*ptr;

	ptr = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		ptr = line_check(line, len);
		if (line != 0)
			*linecount = *linecount + 1;
	}
	if (ptr[0] < 1 || ptr[1] != 1 || ptr[2] != 1)
		item_error(line, ptr);
	free(line);
}

char	**map_check(char *filename, t_items *item)
{
	int		fd;
	size_t	linecount;
	char	*line;
	char	**map;
	size_t	len;

	linecount = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nUnable to open file");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line == 0)
	{
		ft_printf("Error\nNo map found\n");
		exit(EXIT_FAILURE);
	}
	len = check_first_line(line);
	linecount++;
	iterate_map(fd, &linecount, line, len);
	close(fd);
	map = make_map_array(filename, linecount, item);
	return (map);
}
