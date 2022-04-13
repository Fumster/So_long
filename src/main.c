#include "../hdr/so_long.h"

int main(void)
{
	t_mlx	mlx;
	mlx.mlx  = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 512, 512, "Hello_window");
	mlx_hook(mlx.window, 17, 0, dstr_w, &mlx);
	mlx_loop(mlx.mlx);
}
