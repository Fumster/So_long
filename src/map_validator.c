/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:28:20 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/02 18:03:20 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

void	check_sprites(t_vars *vars, char **map, int i, int j)
{
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	while (j < vars->map_h)
	{
		while (i < vars->map_w)
		{
			if (map[j][i] == 'P')
				player++;
			if (map[j][i] == 'E')
				exit++;
			if (map[j][i] == 'C')
				collect++;
			i++;
		}
		i = 0;
		j++;
	}

}

void	check_borders(t_vars *vars, char **map, int i, int j)
{
	int	err;
	
	err = 0;
	while (i < vars->map_w)
	{
		if(map[0][i] != '1' || map[vars->map_h - 1][i] != '1')
			err++;
		i++;
	}
	while (j < vars->map_h)
	{
		if(map[j][0] != '1' || map[j][vars->map_w - 1] != '1')
			err++;
		j++;
	}
	if (err > 0)
	{
		vars->exit_msg = "Error\nMap is not bordered";
		exit_now(vars);
	}
}

void check_rectangle(t_vars *vars, char **map, int i, int j)
{
	while(map[j])
	{
		while(map[j][i])
			i++;
		if (i != vars->map_w)
		{
			vars->exit_msg = "Error\nMap is not rectangle";
			exit_now(vars);
		}
		i = 0;
		j++;
	}

}
void check_symbols(t_vars *vars, char **map, int i, int j)
{
	while(map[j])
	{
		while(map[j][i])
		{
			if(map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'P'
				&& map[j][i] != 'E' && map[j][i] != 'C')
			{
				vars->exit_msg = "Error\nUndefined map symbol";
				exit_now(vars);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int validate_map (t_vars *vars)
{
	check_symbols(vars, vars->map, 0, 0);
	check_rectangle(vars, vars->map, 0, 0);
	check_borders(vars, vars->map, 0, 0);
	check_sprites(vars, vars->map, 0, 0);
	return (0);
}
