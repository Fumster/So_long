/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:37:19 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/02 12:58:15 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->window = NULL;
	vars->map[0] = NULL;
	vars->exit_msg = "Done";
	vars->map_w = 0;
	vars->map_h = 0;
	vars->collected = 0;
	return (0);
}
