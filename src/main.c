/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:18:14 by fchrysta          #+#    #+#             */
/*   Updated: 2022/04/15 19:01:13 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int add_img_to_end(t_vars *vars)
{
	if (vars->wall.width > 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img, 
				vars->player.x, vars->player.y);
		vars->player.x += 42;
		vars->wall.width -= 1;
		usleep(20000);
	}
	return(0);
}

int main(void)
{
	t_vars		vars;

	vars.wall.width = 20;
	vars.player.x = 1;
	vars.player.y = 1;
	vars.mlx  = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 2520, 1302, "Hello_window");
	vars.player.img = mlx_xpm_file_to_image(vars.mlx, 
			"img/wall.xpm", &vars.player.width, &vars.player.height);
	mlx_hook(vars.window, 17, 0, dstr_w, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop_hook(vars.mlx, add_img_to_end, &vars);
	mlx_loop(vars.mlx);
}
