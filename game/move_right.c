/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:27:58 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 18:20:45 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	condition_right_c0(t_game *game)
{
	int		x;
	int		y;
	int		c;
	char	**matrix;

	x = game->dimensions->x;
	y = game->dimensions->y;
	c = game->collectibles;
	matrix = game->dimensions->map_matrix;
	if (matrix[y][x + 1] != '1' && (matrix[y][x + 1] != 'E' || c == 0))
	{
		if (game->dimensions->map_matrix[y][x + 1] == 'C')
			game->collectibles--;
		if (game->dimensions->map_matrix[y][x + 1] == 'E')
			ft_freematrix(matrix);
		if (game->dimensions->map_matrix[y][x + 1] == 'F')
		{
			ft_printf("YOU LOSE!");
			ft_freematrix(matrix);
		}
		game->dimensions->map_matrix[y][x] = '0';
		game->dimensions->map_matrix[y][x + 1] = 'P';
		game->dimensions->x = x + 1;
		game->moves += 1;
	}
}

void	do_right(int key, t_game *game)
{
	if (key == 2)
	{
		condition_right_c0(game);
	}
}
