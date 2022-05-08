/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:52:46 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 17:30:13 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	handle_next_enemy_step(t_vars *vars, int x, int y)
{
	if (x == vars->player.x && y == vars->player.y)
	{
		vars->exit_msg = "You killed by patrol\nThanks for playing";
		exit_now(vars);
	}
	if (vars->map[y][x] == '0' || vars->map[y][x] == 'P')
		return (1);
	return (0);
}

void	get_next_coord(t_vars *vars, int *x, int *y, int i)
{
	int	rand_num;

	rand_num = rand() % 4;
	*x = vars->enemy[i].x;
	*y = vars->enemy[i].y;
	if (rand_num == 0)
		*x += 1;
	else if (rand_num == 1)
		*x -= 1;
	else if (rand_num == 2)
		*y += 1;
	else if (rand_num == 3)
		*y -= 1;
}

int	move_enemy(t_vars *vars)
{
	int	i;
	int	can_move;
	int	x;
	int	y;

	i = vars->enemy_cntr;
	i--;
	while (i > -1)
	{
		get_next_coord(vars, &x, &y, i);
		can_move = handle_next_enemy_step(vars, x, y);
		if (can_move)
		{
			mlx_put_image_to_window(vars->mlx, vars->window, vars->floor.img,
				vars->enemy[i].x * 42, vars->enemy[i].y * 42);
			mlx_put_image_to_window(vars->mlx, vars->window,
				vars->enemy[0].img, x * 42, y * 42);
			vars->enemy[i].x = x;
			vars->enemy[i].y = y;
		}
		i--;
	}
	return (0);
}
