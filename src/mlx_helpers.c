#include "../hdr/so_long.h"

int	dstr_w(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit (0);
}

int key_hook(int keycode, void *mlx)
{
	(void)mlx;
	ft_printf("keycode is %d\n", keycode);
	if (keycode == 65307)
		dstr_w(mlx);
	return (keycode);
}
