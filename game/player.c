/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:24:29 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 16:19:50 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_player_open(t_game *game)
{
	game->player_open.framecount = 0;
	game->player_open.p_img1 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player1.xpm", &game->img_size.img_width,
			&game->img_size.img_height);
	game->player_open.p_img2 = mlx_xpm_file_to_image(game->mlx,
			"assets/Player2.xpm", &game->img_size.img_width,
			&game->img_size.img_height);
}

void	draw_player(t_game *game, int i, int j, char c)
{
	if (c == 'P')
		player_animation(game, j, i);
}
