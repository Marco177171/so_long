/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_coll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:40:19 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 14:27:38 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coll_animation(t_game *game, int j, int i)
{
	if (game->collect.framecount == 0)
		game->coll = game->collect.img1;
	else if (game->collect.framecount == 3)
		game->coll = game->collect.img2;
	else if (game->collect.framecount == 6)
		game->coll = game->collect.img3;
	game->collect.framecount += 1;
	if (game->collect.framecount == 9)
		game->collect.framecount = 0;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->coll, j, i);
}
