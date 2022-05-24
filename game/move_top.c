/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:26:36 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:19:58 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	condition_top_c0(t_game *game)
{
	int		x;
	int		y;
	int		c;
	char	**matrix;

	x = game->dimensions->x;
	y = game->dimensions->y;
	c = game->collectibles;
	matrix = game->dimensions->map_matrix;
	if (matrix[y - 1][x] != '1' && (matrix[y - 1][x] != 'E' || c == 0))
	{
		if (game->dimensions->map_matrix[y - 1][x] == 'C')
			game->collectibles--;
		if (game->dimensions->map_matrix[y - 1][x] == 'E')
			ft_freematrix(matrix);
		if (game->dimensions->map_matrix[y - 1][x] == 'F')
		{
			ft_printf("YOU LOSE!");
			ft_freematrix(matrix);
		}
		game->dimensions->map_matrix[y][x] = '0';
		game->dimensions->map_matrix[y - 1][x] = 'P';
		game->dimensions->y = y - 1;
		game->moves += 1;
	}
}

void	do_top(int key, t_game *game)
{
	if (key == 13)
	{
		condition_top_c0(game);
	}
}
