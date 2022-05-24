/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:39:37 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 14:28:04 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	door_animation_open(t_game *game, int j, int i)
{
	if (game->door_open.framecount == 0)
		game->door = game->door_open.img1;
	else if (game->door_open.framecount == 2)
		game->door = game->door_open.img2;
	else if (game->door_open.framecount == 4)
		game->door = game->door_open.img3;
	game->door_open.framecount += 1;
	if (game->door_open.framecount == 6)
		game->door_open.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->door, j, i);
}
