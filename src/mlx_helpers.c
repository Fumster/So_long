#include "../hdr/so_long.h"

int	dstr_w(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit (0);
}

int key_hook(int keycode, t_vars *vars)
{
	//(void)vars;
	ft_printf("keycode is %d\n", keycode);
	if (keycode == ESC_KEY)
		dstr_w(vars);
	if (keycode == W_KEY)
	{
		vars->player.y -= 35;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img, 
								vars->player.x, vars->player.y);
	}
	if (keycode == S_KEY)
	{
		vars->player.y += 35;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img, 
								vars->player.x, vars->player.y);
	}
	if (keycode == A_KEY)
	{
		vars->player.x -= 35;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img, 
								vars->player.x, vars->player.y);
	}
	if (keycode == D_KEY)
	{
		vars->player.x += 35;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img, 
								vars->player.x, vars->player.y);
	}
	return (keycode);
}
