#include "so_long.h"

void	check_last_line(char **map, size_t linecount)
{
	int	i;

	i = 0;
	while(map[linecount - 1][i] != 0)
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

size_t	check_first_line(char *line)
{
	size_t	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	while (line[i] != 0 && line[i] != '\n')
	{
		if (line[i] != '1')
			map_error(line, 1);
		i++;
	}
	return (len);
}

int	*line_check(char *line, size_t len)
{
	size_t	i;
	static int items[] = {0, 0, 0};
	char str[6]= "01PCE";

	if(line == 0)
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
		if (ft_strchr(str, line[i]) == 0)
			map_error(line, 2);
		i++;
	}
	if (i != len - 1)
		map_error(line, 0);
	if (line[0] != '1' || line[i - 1] != '1')
		map_error(line, 1);
	return (items);
}

void	iterate_map(int fd, size_t *linecount, char *line)
{
	int	*ptr;
	size_t	len;

	len = 0;
	ptr = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (*linecount == 0)
			len = check_first_line(line);
		else
			ptr = line_check(line, len);
		if (line != 0)
			*linecount = *linecount + 1;
	}
	if (ptr[0] < 1 || ptr[1] != 1 || ptr[2] != 1 || *linecount >= len - 1)
	{
		if (*linecount >= len - 1)
			map_error(line, 0);
		else
			item_error(line, ptr);
	}
	ptr = 0;
	free(line);
}

void	map_check(char *filename, t_data *data)
{
	int		fd;
	size_t	linecount;
	char	*line;

	line = "";
	linecount = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	iterate_map(fd, &linecount, line);
	close(fd);
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		exit(EXIT_FAILURE);
	make_map_array(fd, linecount, data);
}