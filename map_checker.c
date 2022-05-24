/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:21:15 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:11:36 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s ERROR!\n", str);
	exit(1);
}

void	ft_general_check(t_coordinate *data)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			c = data->map_matrix[y][x];
			if ((y == 0 || y == data->map_height - 1) && c != '1')
				ft_error("Map");
			if ((x == 0 || x == data->map_lenght - 1) && c != '1')
				ft_error("Map");
			if (c != '1' && c != 'E' && c != 'C'
				&& c != '0' && c != 'P' && c != 'F')
				ft_error("Map");
			x++;
		}
		y++;
	}
}

void	ft_all_checkers(t_coordinate *data)
{
	if (data->map_height < 3)
		ft_error("Height");
	if (data->map_lenght < 3)
		ft_error("Lenght");
	ft_general_check(data);
	ft_element_collectible(data);
	ft_element_exit(data);
	ft_element_player(data);
}
