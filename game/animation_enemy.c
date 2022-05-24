/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:33:18 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 18:02:02 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_animation(t_game *game, int j, int i)
{
	if (game->enemy_open.framecount == 0)
		game->enemy_open.curr_img = game->enemy_open.img1;
	else if (game->enemy_open.framecount == 2)
		game->enemy_open.curr_img = game->enemy_open.img2;
	game->enemy_open.framecount += 1;
	if (game->enemy_open.framecount == 3)
		game->enemy_open.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->enemy_open.curr_img, j, i);
}
