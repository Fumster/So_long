/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:37:19 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 17:30:54 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->window = NULL;
	vars->map[0] = NULL;
	vars->exit_msg = "Thanks for playing!\n";
	vars->map_w = 0;
	vars->map_h = 0;
	vars->need_collect = 0;
	vars->enemy_cntr = 0;
	vars->steps = 0;
}

void	init_player(t_vars *vars, int x, int y)
{
	vars->player.x = x;
	vars->player.y = y;
}

void	init_enemy(t_vars *vars, int x, int y)
{
	static int	i;

	vars->enemy[i].x = x;
	vars->enemy[i].y = y;
	i++;
	vars->enemy_cntr = i;
}

void	init_sprites(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < vars->map_h)
	{
		while (i < vars->map_w)
		{
			if (vars->map[j][i] == 'P')
				init_player(vars, i, j);
			if (vars->map[j][i] == 'D')
				init_enemy(vars, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
