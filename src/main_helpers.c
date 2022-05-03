/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:37:19 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/03 18:09:23 by fchrysta         ###   ########.fr       */
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
	vars->collected = 0;
	vars->need_collect = 0;
	vars->enemy_cntr = 0;
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
			{
				vars->player.x = i * 42;
				vars->player.y = j * 42;
				return ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
