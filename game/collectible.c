/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:38:13 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 18:35:00 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_count_collectible(t_coordinate *data, t_game *game)
{
	int		x;
	int		y;
	char	c;
	int		i;

	y = 0;
	game->collectibles = 0;
	i = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_lenght)
		{
			c = data->map_matrix[y][x];
			if (c == 'C')
				i++;
			x++;
		}
		y++;
	}
	game->collectibles = i;
	return (i);
}

void	img_coll_open(t_game *game)
{
	game->collect.framecount = 0;
	game->collect.img1 = mlx_xpm_file_to_image(game->mlx, "assets/Coin1.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->collect.img2 = mlx_xpm_file_to_image(game->mlx, "assets/Coin2.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
	game->collect.img3 = mlx_xpm_file_to_image(game->mlx, "assets/Coin3.xpm",
			&game->img_size.img_width, &game->img_size.img_height);
}

void	draw_coll(t_game *game, int i, int j, char c)
{
	if (c == 'C' && game->collectibles > 0)
		coll_animation(game, j, i);
}
