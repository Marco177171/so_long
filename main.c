/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:05:25 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 18:25:35 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_coordinate	data;
	t_game			game;

	if (argc != 2)
		ft_error("ARG");
	read_file(argv[1], &data);
	ft_count_collectible(&data, &game);
	ft_all_checkers(&data);
	game.dimensions = &data;
	img_door_open(&game);
	img_coll_open(&game);
	img_player_open(&game);
	img_enemy_open(&game);
	game_init(&game);
	mlx_loop_hook(game.mlx, draw, (void *)&game);
	mlx_key_hook(game.mlx_win, deal_key, &game);
	mlx_loop(game.mlx);
	return (0);
}
