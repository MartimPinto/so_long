# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:57:58 by mcarneir          #+#    #+#              #
#    Updated: 2023/07/07 16:44:43 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./Libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long
NAME_BNS = so_long_bonus

SRC =	src/main.c \
	src/map_check.c \
	src/map_check_utils.c \
	src/init.c \
	src/free.c \
	src/utils_general.c \
	src/render.c \
	src/move_p.c \
	src/walk.c \

SRC_BNS = src_bonus/main_bonus.c \
	src_bonus/map_check_bonus.c \
	src_bonus/map_check_utils_bonus.c \
	src_bonus/init_bonus.c \
	src_bonus/free_bonus.c \
	src_bonus/utils_general_bonus.c \
	src_bonus/render_bonus.c \
	src_bonus/move_p_bonus.c \
	src_bonus/walk_bonus.c \
	src_bonus/idle_poses_bonus.c \
	src_bonus/collect_animations_bonus.c \
	src_bonus/Walk_Animation_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

LIBFT = Libs/libft/libft.a

all: deps $(NAME)

deps: 
	$(MAKE) -C ./Libs/libft
	$(MAKE) -C ./Libs/minilibx-linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

bonus: deps $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BNS)

clean: 
	$(MAKE) clean -C ./Libs/libft
	$(MAKE) clean -C ./Libs/minilibx-linux
	@$(RM) $(OBJ) $(OBJ_BNS)

fclean : clean
	@$(RM) $(LIBFT) $(NAME) $(NAME_BNS)

re: fclean all bonus
	