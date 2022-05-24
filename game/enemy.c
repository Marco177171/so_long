/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:36:52 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 17:59:23 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_enemy_open(t_game *game)
{
	game->enemy_open.framecount = 0;
	game->enemy_open.img1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Enemy1.xpm", &game->img_size.img_width,
			&game->img_size.img_height);
	game->enemy_open.img2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Enemy2.xpm", &game->img_size.img_width,
			&game->img_size.img_height);
}

void	draw_enemy(t_game *game, int i, int j, char c)
{
	if (c == 'F')
		enemy_animation(game, j, i);
}
