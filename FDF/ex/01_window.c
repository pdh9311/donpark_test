#include <mlx.h>

/** window open
 */
int	main(void)
{
	void	*mlx1;
	void	*mlx2;
	void	*mlx_win1;
	void	*mlx_win2;

	mlx1 = mlx_init();
	mlx2 = mlx_init();
	mlx_win1 = mlx_new_window(mlx1, 600, 600, "Helloworld!");
	mlx_win2 = mlx_new_window(mlx2, 800, 800, "Helloworld!");
	mlx_loop(mlx1);
	mlx_loop(mlx2);
	return (0);
}
