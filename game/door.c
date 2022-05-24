/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:36:52 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:31:37 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_door_open(t_game *game)
{
	game->door_open.framecount = 0;
	game->door_open.img1 = mlx_xpm_file_to_image(game->mlx, "assets/Exit1.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->door_open.img2 = mlx_xpm_file_to_image(game->mlx, "assets/Exit2.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->door_open.img3 = mlx_xpm_file_to_image(game->mlx, "assets/Exit3.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	draw_door(t_game *game, int i, int j, char c)
{
	if (c == 'E')
		door_animation_open(game, j, i);
}
