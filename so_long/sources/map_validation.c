/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:02:39 by tkartasl          #+#    #+#             */
/*   Updated: 2024/01/24 15:51:59 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char	*str)
{
	ft_printf("Map is not functional\n");
	free(str);
	str == NULL;
	exit (EXIT_FAILURE);
}

int	check_first_line(char *line)
{
	int	len;
	
	len = ft_strlen(line);
	while (*line != 0)
	{
		if (*line != 1)	
			map_error(line);
		line++;					
	}
	return (len);
}

int	*line_check(char *line, int len)
{
	int	i;		 
	static int checker[] = {0, 0, 0};
	
	i = 0;
	if(ft_strlen(line) != len)
		map_error(line);
	if (line[i] != 1 || line[ft_strlen(line) - 1] != 1)
		map_error(line);
	while (line[i] != 0)
	{
		if (mapline[i] == 'C')
			checker[0] = 1;
		if (mapline[i] == 'E')
			checker[1] = 1;
		if (mapline[i] == 'P')
			checker[2] = 1;
		i++;	
	}
	return (checker);
}

int	iterate_map(int fd)
{
	int		*ptr;
	int		len;
	int		linecount;
	char	*line;
	
	linecount = 0;
	line = "";
	len = 0;
	ptr = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (linecount == 0)
			len = ft_strlen(line);
		ptr = line_check(line, len);		
		linecount++;	
	}
	if (ptr[0] < 1 || ptr[1] < 1 || ptr[2] < 1 || linecount >= len)
	{
		checker = 0;
		map_error(line);
	}
	free(line);
	return (linecount);
}

void	map_check(char *filename);
{
	int	fd;
	
	linecount = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	iterate_map(fd, &linecount);
	close(fd);
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		exit (EXIT_FAILURE);
	make_map_array(fd, linecount);	
}
