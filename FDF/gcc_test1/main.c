#include "../minilibx-linux/mlx_int.h"
#include "../minilibx-linux/mlx.h"

int main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
