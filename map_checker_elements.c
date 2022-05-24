/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:17:46 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:10:18 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_element_exit(t_coordinate *data)
{
	int		x;
	int		y;
	char	c;
	int		i;

	y = 0;
	i = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			c = data->map_matrix[y][x];
			if (c == 'E')
				i++;
			x++;
		}
		y++;
	}
	if (i == 0)
		ft_error("NO EXIT!");
}

void	ft_element_player(t_coordinate *data)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			if (data->map_matrix[y][x] == 'P')
			{
				i++;
				data->x = x;
				data->y = y;
			}
			x++;
		}
		y++;
	}
	if (i != 1)
		ft_error("PLAYER NUMBER ERROR!");
}

void	ft_element_collectible(t_coordinate *data)
{
	int		x;
	int		y;
	char	c;
	int		i;

	y = 0;
	i = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			c = data->map_matrix[y][x];
			if (c == 'C')
				i++;
			x++;
		}
		y++;
	}
	if (i < 1)
		ft_error("NO COLLECTIBLE!");
}
