/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:35:29 by masebast          #+#    #+#             */
/*   Updated: 2022/05/17 15:31:30 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_floor_open(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/Floor.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	draw_floor(t_game *game, int i, int j, char c)
{
	img_floor_open(game);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j, i);
}
