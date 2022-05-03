/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:05 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/03 15:25:46 by fchrysta         ###   ########.fr       */
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
		vars->exit_msg = "Error\nCan not open map";
		exit_now(vars);
	}
	vars->map[i] = get_next_line(fd);
	while (vars->map[i])
	{
		i++;
		vars->map[i] = get_next_line(fd);
	}
	delete_linebreaks(vars);
	write_map_size(vars);
	validate_map(vars);
}
