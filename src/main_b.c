/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:22:44 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/07 17:11:28 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	put_animation_picture(t_vars *vars, int x, int y, int c)
{
	if (c == 0)
		mlx_put_image_to_window(vars->mlx, vars->window,
				vars->floor.img, x * 42, y * 42);
	else if (c == 2000)
		mlx_put_image_to_window(vars->mlx, vars->window,
				vars->item.img, x * 42, y * 42);

}

int	animate_items(t_vars *vars)
{
	int			i;
	int			j;
	static int	c;

	i = 0;
	j = 0;
	while (vars->map[j])
	{
		while (vars->map[j][i])
		{
			if(vars->map[j][i] == 'C')
				put_animation_picture(vars, i, j, c);
			i++;
		}
		i = 0;
		j++;
	}
	if (c < 4000)
		c++;
	else if (c == 4000)
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
