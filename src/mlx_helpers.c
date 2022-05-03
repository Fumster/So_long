/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:05:39 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/03 18:27:42 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	dstr_w(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	ft_printf("keycode is %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		vars->exit_msg = "Exit by ESC, thanks for playing!";
		exit_now(vars);
	}
	if (keycode == W_KEY)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			vars->player.x, vars->player.y);
		vars->player.y -= 42;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			vars->player.x, vars->player.y);
	}
	if (keycode == S_KEY)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			vars->player.x, vars->player.y);
		vars->player.y += 42;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			vars->player.x, vars->player.y);
	}
	if (keycode == A_KEY)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			vars->player.x, vars->player.y);
		vars->player.x -= 42;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			vars->player.x, vars->player.y);
	}
	if (keycode == D_KEY)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			vars->player.x, vars->player.y);
		vars->player.x += 42;
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			vars->player.x, vars->player.y);
	}
	return (0);
}

void	open_error(t_vars *vars, char *msg)
{
		vars->exit_msg = msg;
		exit_now(vars);
}
void	open_images (t_vars *vars)
{
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm",
		&vars->player.width, &vars->player.height);
	if (!vars->player.img)
		open_error(vars, "Error\nCould not open player image\n");
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm",
		&vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		open_error(vars, "Error\nCould not open wall image\n");
	vars->floor.img = mlx_xpm_file_to_image(vars->mlx, "img/floor.xpm",
		&vars->floor.width, &vars->floor.height);
	if (!vars->floor.img)
		open_error(vars, "Error\nCould not open floor image\n");
	vars->item.img = mlx_xpm_file_to_image(vars->mlx, "img/item.xpm",
		&vars->item.width, &vars->item.height);
	if (!vars->item.img)
		open_error(vars, "Error\nCould not open item image\n");
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "img/exit.xpm",
		&vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		open_error(vars, "Error\nCould not open exit image\n");
}
