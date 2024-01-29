#include "../include/so_long.h"

void ft_error(void)
{
	mlx_strerror(mlx_errno);
	exit(EXIT_FAILURE);

}
int main()
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	/*mlx_image_t	*floor;			
	mlx_image_t	*player;
	mlx_image_t	*end;
	mlx_image_t	*collect;*/
	
	mlx = mlx_init(WIDTH, HEIGHT, "Best Game Ever!", true);
	if(mlx == 0)
		ft_error();
	wall = mlx_new_image(mlx, 50, 50);
	if (wall == 0)
		ft_error();
	ft_memset(wall->pixels, 255, wall->width * wall->height * sizeof(int));
	if(mlx_image_to_window(mlx, wall, 0, 50) < 0)
		ft_error();
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}