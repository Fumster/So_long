/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:52:46 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/08 18:15:40 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	check_patrol(t_vars *vars, int x, int y)
{
	int	i;

	i = vars->enemy_cntr;
	i--;
	while (i > -1)
	{
		if (x == vars->enemy[i].x && y == vars->enemy[i].y)
		{
			vars->exit_msg = "You killed by patrol\nThanks for playing";
			exit_now(vars);
		}
		i--;
	}
}

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
	check_patrol(vars, x, y);
	return (1);
}

void	print_message(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->steps);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->floor.img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->window,
		vars->floor.img, 42, 0);
	mlx_string_put(vars->mlx, vars->window, 38, 25, 51000, "STEPS");
	mlx_string_put(vars->mlx, vars->window, 13, 25, 51000, str);
	if (str)
		free(str);
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
		print_message(vars);
	}
}
