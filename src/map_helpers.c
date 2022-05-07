/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:05 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/07 11:36:04 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../hdr/so_long.h"

void	delete_linebreaks(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[j])
	{
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == '\n')
				vars->map[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

void	call_big_map_error(t_vars *vars)
{
	vars->exit_msg = "Error\nMap is too big, max map size is 60X30n";
	exit_now(vars);
}

void	write_map_size(t_vars *vars)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (vars->map[h])
		h++;
	while (vars->map[0][w])
		w++;
	if (w > 60 || h > 30)
		call_big_map_error(vars);
	vars->map_w = w;
	vars->map_h = h;
}

void	validate_map(t_vars *vars)
{
	check_symbols(vars, vars->map, 0, 0);
	check_rectangle(vars, vars->map, 0, 0);
	check_borders(vars, vars->map, 0, 0);
	check_sprites(vars, vars->map);
}

void	read_map(t_vars *vars, char *path)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		vars->exit_msg = "Error\nCan not open map\n";
		exit_now(vars);
	}
	vars->map[i] = get_next_line(fd);
	while (vars->map[i])
	{
		i++;
		vars->map[i] = get_next_line(fd);
		if (i > 200)
			call_big_map_error(vars);
	}
	delete_linebreaks(vars);
	write_map_size(vars);
	validate_map(vars);
}
