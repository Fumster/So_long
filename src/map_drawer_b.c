/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:06:06 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 14:28:45 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	put_image(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->wall.img,
			x * 42, y * 42);
	else if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			x * 42, y * 42);
	else if (vars->map[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			x * 42, y * 42);
	else if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->item[0].img,
			x * 42, y * 42);
	else if (vars->map[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->exit.img,
			x * 42, y * 42);
	else if (vars->map[y][x] == 'D')
		mlx_put_image_to_window(vars->mlx, vars->window, vars->enemy[0].img,
			x * 42, y * 42);
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->map_h)
	{
		while (i < vars->map_w)
		{
			mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
				i * 42, j * 42);
			put_image(vars, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
