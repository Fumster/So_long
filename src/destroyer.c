/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:42:36 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/02 14:27:04 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	exit_now(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->window)
		mlx_destroy_window(vars->mlx, vars->window);
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	if (vars->exit_msg)
		ft_printf("%s", vars->exit_msg);
	exit(0);
}
