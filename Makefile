# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:45:38 by aleite-b          #+#    #+#              #
#    Updated: 2024/01/08 15:20:09 by aleite-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
ARCHIVES = libft/libft.a minilibx-linux/libmlx_Linux.a

SOURCES = main.c \
			map/file.c \
			map/map.c \
			map/map_utils.c \
			map/utils.c \
			map/utils2.c \
			game/assets.c \
			game/render_map.c \
			game/play_game.c \
			game/move.c \
			game/move_utils.c
			
OBJECTS = $(SOURCES:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME): $(OBJECTS) 
	make all -C libft
	$(CC) $(FLAGS) -lXext -lX11 -o $(NAME) $(OBJECTS) $(ARCHIVES)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS)
	make fclean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft


.PHONY: all clean fclean re
