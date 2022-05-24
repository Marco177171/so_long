/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:25:17 by masebast          #+#    #+#             */
/*   Updated: 2022/05/18 14:28:34 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_wall_open(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/Wall.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	draw_wall(t_game *game, int i, int j, char c)
{
	img_wall_open(game);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->wall, j, i);
}
