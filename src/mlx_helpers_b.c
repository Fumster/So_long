/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:05:39 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 14:56:54 by fchrysta         ###   ########.fr       */
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
	int	x;
	int	y;

	x = vars->player.x;
	y = vars->player.y;
	if (keycode == ESC_KEY)
	{
		vars->exit_msg = "Exit by ESC\nthanks for playing!\n";
		exit_now(vars);
	}
	if (keycode == W_KEY)
		move_player(vars, x, y - 1);
	if (keycode == S_KEY)
		move_player(vars, x, y + 1);
	if (keycode == A_KEY)
		move_player(vars, x - 1, y);
	if (keycode == D_KEY)
		move_player(vars, x + 1, y);
	return (0);
}

void	*do_open(t_vars *vars, char *picture)
{
	void	*pic_pointer;

	pic_pointer = mlx_xpm_file_to_image(vars->mlx, picture,
			&vars->player.width, &vars->player.height);
	if (!vars->player.img)
	{
		ft_printf("Error\nCould not open image\n");
		vars->exit_msg = picture;
		exit_now(vars);
	}
	return (pic_pointer);
}

void	open_images(t_vars *vars)
{
	vars->player.img = do_open(vars, "img/player.xpm");
	vars->wall.img = do_open(vars, "img/wall.xpm");
	vars->floor.img = do_open(vars, "img/floor.xpm");
	vars->item[0].img = do_open(vars, "img/item.xpm");
	vars->item[1].img = do_open(vars, "img/item2.xpm");
	vars->item[2].img = do_open(vars, "img/item3.xpm");
	vars->enemy[0].img = do_open(vars, "img/enemy.xpm");
	vars->exit.img = do_open(vars, "img/exit.xpm");
}
