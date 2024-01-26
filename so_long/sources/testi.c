#include "../libft/libft.h"
#include <stdio.h>

typedef struct s_items
{
	int	c_count;
	int	exit;
	int p_pos_r;
	int	p_pos_c;
}		t_items;

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











int main(void)
{
	char	*str;
	int		fd;
	t_items	item;
	char	**map;

	ft_memset(&item, 0, sizeof(t_items));
	str = "../maps/map1.ber";
	fd = open(str, O_RDONLY);
	map = make_map_array(fd, 6, &item);
}