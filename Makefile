# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 15:57:58 by mcarneir          #+#    #+#              #
#    Updated: 2023/07/04 16:13:34 by mcarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L ./Libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
RM = rm -f

NAME = so_long

SRC =	main.c \
	map_check.c \
	map_check_utils.c \
	init.c \
	free.c \
	utils_general.c \
	render.c \
	move_p.c \
	walk.c \

OBJ = $(SRC:.c=.o)

LIBFT = Libs/libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./Libs/libft
	$(MAKE) -C ./Libs/minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean: 
	$(MAKE) clean -C ./Libs/libft
	$(MAKE) clean -C ./Libs/minilibx-linux
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(LIBFT) $(NAME)

re: fclean all	
	