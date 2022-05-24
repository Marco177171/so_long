/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masebast <masebast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:06:08 by masebast          #+#    #+#             */
/*   Updated: 2022/05/20 15:58:02 by masebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>

typedef struct s_movements
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_movements;

typedef struct s_player
{
	t_movements	move;
	int			framecount;
	void		*p_img1;
	void		*p_img2;
}	t_player;

typedef struct s_enemy
{
	int			framecount;
	void		*curr_img;
	void		*img1;
	void		*img2;
}	t_enemy;

typedef struct s_coordinate
{
	t_player	player;
	int			x;
	int			y;
	int			map_height;
	int			map_lenght;
	char		**map_matrix;
}	t_coordinate;

typedef struct s_door
{
	int		framecount;
	void	*img1;
	void	*img2;
	void	*img3;
}	t_door;

typedef struct s_coll
{
	int		framecount;
	void	*img1;
	void	*img2;
	void	*img3;
}	t_coll;

typedef struct s_img
{
	void	*mlx;
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_game
{
	t_coordinate	*dimensions;
	t_img			img_size;
	t_door			door_open;
	t_player		player_open;
	t_coll			collect;
	t_enemy			enemy_open;
	int				collectibles;
	int				moves;
	void			*mlx;
	void			*mlx_win;
	void			*floor;
	void			*wall;
	void			*door;
	void			*player;
	void			*coll;
	int				frame;
}	t_game;

//map part
void		read_file(char *nome_file, t_coordinate *data);
//map elements check
void		ft_element_exit(t_coordinate *data);
void		ft_element_player(t_coordinate *data);
void		ft_element_collectible(t_coordinate *data);
//map checkers
void		ft_error(char *str);
void		ft_all_checkers(t_coordinate *data);
//game init
void		game_init(t_game *game);
//game draw
void		draw_floor(t_game *game, int i, int j, char c);
void		img_floor_open(t_game *game);
void		img_coll_open(t_game *game);
void		img_player_open(t_game *game);
void		img_enemy_open(t_game *game);
void		draw_wall(t_game *game, int i, int j, char c);
void		draw_door(t_game *game, int i, int j, char c);
void		draw_player(t_game *game, int i, int j, char c);
void		draw_enemy(t_game *game, int i, int j, char c);
void		draw_coll(t_game *game, int i, int j, char c);
void		coll_animation(t_game *game, int j, int i);
void		player_animation(t_game *game, int j, int i);
void		enemy_animation(t_game *game, int j, int i);
int			draw(t_game *game);
//game movements
void		do_right(int key, t_game *game);
void		do_left(int key, t_game *game);
void		do_top(int key, t_game *game);
void		do_bottom(int key, t_game *game);
//game utils
int			ft_count_collectible(t_coordinate *data, t_game *game);
int			deal_key(int key, t_game *game);
void		ft_freematrix(char **matrix);
void		ft_exit(int key, t_game *game);
//main
int			main(int argc, char **argv);
void		animation_setup(t_game *game);
void		door_animation_open(t_game *game, int j, int i);
void		img_door_open(t_game *game);

#endif