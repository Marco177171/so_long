/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:33:15 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 16:03:29 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_key(int key)
{
	return (key == 2 || key == 0 || key == 13 || key == 1 || key == 53);
}

int	deal_key(int key, t_game *game)
{
	if (ft_key(key))
	{
		mlx_clear_window(game->mlx, game->mlx_win);
		if (key == 2)
			do_right(key, game);
		if (key == 0)
			do_left(key, game);
		if (key == 13)
			do_top(key, game);
		if (key == 1)
			do_bottom(key, game);
		if (key == 53)
			ft_exit(key, game);
		draw(game);
		ft_printf("%d\n", game->moves);
	}
	return (0);
}
