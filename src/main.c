/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:22:44 by fchrysta          #+#    #+#             */
/*   Updated: 2022/05/02 18:03:29 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/so_long.h"

int	main(void)
{
	t_vars	vars;
	int		i;

	i = 0;
	init_vars(&vars);
	read_map(&vars, "maps/lvl_1.ber");
	while (vars.map[i])
	{
		ft_printf("%s\n", vars.map[i]);
		i++;
	}
	exit_now(&vars);
}
