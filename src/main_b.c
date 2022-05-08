/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:22:44 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 17:15:15 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	put_picture(t_vars *vars, int x, int y, void *pict)
{
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->floor.img, x * 42, y * 42);
	mlx_put_image_to_window(vars->mlx, vars->window,
		pict, x * 42, y * 42);
}

void	put_animation_picture(t_vars *vars, int c, int i, int j)
{
	while (vars->map[j])
	{
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'C')
			{
				if (c == 0)
					put_picture(vars, i, j, vars->item[0].img);
				else if (c == 2000)
					put_picture(vars, i, j, vars->item[1].img);
				else if (c == 4000)
					put_picture(vars, i, j, vars->item[2].img);
				else if (c == 6000)
					put_picture(vars, i, j, vars->item[1].img);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int	animate_items(t_vars *vars)
{
	static int	c;

	if (c == 0 || c == 2000 || c == 4000 || c == 6000)
		put_animation_picture(vars, c, 0, 0);
	if (c == 0 || c == 4000)
		move_enemy(vars);
	if (c < 8000)
		c++;
	else
		c = 0;
	return (0);
}

void	check_extension(t_vars *vars, char *path)
{
	int		i;
	int		t;
	char	*template;

	template = ".ber\0";
	i = 0;
	t = 0;
	while (path[i])
	{
		i++;
	}
	i -= 4;
	while (path[i])
	{
		if (path[i] != template[t])
		{
			vars->exit_msg = "Error\nIncorrect map extension\n";
			exit_now(vars);
		}
		i++;
		t++;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_vars(&vars);
	if (argc != 2)
	{
		vars.exit_msg = "Error\nplease specify map in argument\n";
		exit_now(&vars);
	}
	check_extension(&vars, argv[1]);
	read_map(&vars, argv[1]);
	init_sprites(&vars);
	vars.mlx = mlx_init();
	open_images(&vars);
	vars.window = mlx_new_window(vars.mlx,
			vars.map_w * 42, vars.map_h * 42, "G");
	draw_map(&vars);
	mlx_loop_hook(vars.mlx, animate_items, &vars);
	mlx_hook(vars.window, 17, 0, exit_now, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
}
