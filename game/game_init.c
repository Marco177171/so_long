/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:30:48 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:15:40 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_init(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	x = game->dimensions->map_height * 32;
	y = game->dimensions->map_lenght * 32;
	game->player = game->player_open.p_img1;
	game->mlx_win = mlx_new_window(game->mlx, y, x, "so_long");
	game->moves = 0;
}
