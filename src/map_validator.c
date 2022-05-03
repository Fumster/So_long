/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:28:20 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/03 16:43:55 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	count_sprites(char **map, int i, int j, char symbol)
{
	int	cntr;

	cntr = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == symbol)
				cntr++;
			i++;
		}
		i = 0;
		j++;
	}
	return (cntr);
}

void	check_sprites(t_vars *vars, char **map)
{
	int	player;
	int	exit;
	int	items;

	player = count_sprites(map, 0, 0, 'P');
	exit = count_sprites(map, 0, 0, 'E');
	items = count_sprites(map, 0, 0, 'C');
	vars->need_collect = items;
	if (player != 1 || exit < 1 || items < 1)
	{
		vars->exit_msg = "Error\nCheck sprites, items or exit count at map\n";
		exit_now(vars);
	}
}

void	check_borders(t_vars *vars, char **map, int i, int j)
{
	int	err;

	err = 0;
	while (i < vars->map_w)
	{
		if (map[0][i] != '1' || map[vars->map_h - 1][i] != '1')
			err++;
		i++;
	}
	while (j < vars->map_h)
	{
		if (map[j][0] != '1' || map[j][vars->map_w - 1] != '1')
			err++;
		j++;
	}
	if (err > 0)
	{
		vars->exit_msg = "Error\nMap is not bordered\n";
		exit_now(vars);
	}
}

void	check_rectangle(t_vars *vars, char **map, int i, int j)
{
	while (map[j])
	{
		while (map[j][i])
			i++;
		if (i != vars->map_w)
		{
			vars->exit_msg = "Error\nMap is not rectangle\n";
			exit_now(vars);
		}
		i = 0;
		j++;
	}
}

void	check_symbols(t_vars *vars, char **map, int i, int j)
{
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P'
				&& map[j][i] != 'E' && map[j][i] != 'C')
			{
				vars->exit_msg = "Error\nUndefined map symbol\n";
				exit_now(vars);
			}
			i++;
		}
		i = 0;
		j++;
	}
}
