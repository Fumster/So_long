/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:52:46 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/07 15:12:39 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	handle_next_step(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == '1')
		return (0);
	else if (vars->map[y][x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			x * 42, y * 42);
		vars->need_collect--;
		vars->map[y][x] = '0';
	}
	else if (vars->map[y][x] == 'E')
	{
		if (vars->need_collect)
			return (0);
		else
		{
			vars->exit_msg = "You win!\nThanks for playing\n";
			exit_now(vars);
		}
	}
	return (1);
}

void	move_player(t_vars *vars, int x, int y)
{
	int	can_move;

	can_move = handle_next_step(vars, x, y);
	if (can_move)
	{
		mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
			vars->player.x * 42, vars->player.y * 42);
		mlx_put_image_to_window(vars->mlx, vars->window, vars->player.img,
			x * 42, y * 42);
		vars->player.x = x;
		vars->player.y = y;
		vars->steps++;
		ft_printf("%d steps\n", vars->steps);
	}
}
