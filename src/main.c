/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:22:44 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/03 18:27:45 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	main(void)
{
	t_vars	vars;
	int		i;

	i = 0;
	init_vars(&vars);
	read_map(&vars, "maps/lvl_1.ber");
	init_sprites(&vars);
	vars.mlx = mlx_init();
	open_images(&vars);
	vars.window = mlx_new_window(vars.mlx, vars.map_w * 42, vars.map_h * 42, "G");
	draw_map(&vars);
	while (vars.map[i])
	{
		ft_printf("%s\n", vars.map[i]);
		i++;
	}
	mlx_hook(vars.window, 17, 0, exit_now, &vars);
	mlx_key_hook(vars.window, key_hook, &vars);
	mlx_loop(vars.mlx);
	exit_now(&vars);
}
