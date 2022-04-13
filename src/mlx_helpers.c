#include "../hdr/so_long.h"

int	dstr_w(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit (0);
}
