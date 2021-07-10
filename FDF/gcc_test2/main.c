#include <mlx.h>
#include <mlx_int.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 309, 300, "donpark");
	mlx_loop(mlx);
	return (0);
}
