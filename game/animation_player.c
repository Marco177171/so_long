/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:26:21 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 18:21:18 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_animation(t_game *game, int j, int i)
{
	if (game->player_open.framecount == 0)
		game->player = game->player_open.p_img1;
	else if (game->player_open.framecount == 2)
		game->player = game->player_open.p_img2;
	game->player_open.framecount += 1;
	if (game->player_open.framecount == 3)
		game->player_open.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, j, i);
}
