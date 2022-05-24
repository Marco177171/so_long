# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masebast <masebast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:44:06 by masebast          #+#    #+#              #
#    Updated: 2022/05/20 16:26:12 by masebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -l mlx -framework openGL -framework AppKit
NAME = so_long
SRC = main.c \
map_checker_elements.c \
map_checker.c \
read_map.c \
game/animation_coll.c \
game/animation_door.c \
game/animation_enemy.c \
game/animation_player.c \
game/collectible.c \
game/door.c \
game/enemy.c \
game/floor.c \
game/ft_draw.c \
game/ft_exit.c \
game/ft_freematrix.c \
game/ft_key.c \
game/game_init.c \
game/move_bottom.c \
game/move_left.c \
game/move_right.c \
game/move_top.c \
game/player.c \
game/wall.c

$(NAME):
		make -C libft
		$(CC) $(FLAGS) $(SRC) -o $(NAME) libft/libft.a $(INCLUDE)

clean:
		rm -rf $(NAME)

fclean: clean
		make fclean -C libft

all:	$(NAME)

re:		fclean all