/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:34:38 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 18:41:04 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	img_floor_open(game);
	while (j < game->dimensions->map_height)
	{
		i = 0;
		while (i < game->dimensions->map_lenght)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->floor, i * 32, j * 32);
			draw_coll(game, j * 32, i * 32, game->dimensions->map_matrix[j][i]);
			draw_wall(game, j * 32, i * 32, game->dimensions->map_matrix[j][i]);
			draw_door(game, j * 32, i * 32, game->dimensions->map_matrix[j][i]);
			draw_player(game, j * 32, i * 32,
				game->dimensions->map_matrix[j][i]);
			draw_enemy(game, j * 32, i * 32,
				game->dimensions->map_matrix[j][i]);
			i++;
		}
		j++;
	}
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0, str);
	free(str);
	return (1);
}
