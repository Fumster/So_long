/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:22:44 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/07 15:11:33 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

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
	mlx_hook(vars.window, 17, 0, exit_now, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
}
