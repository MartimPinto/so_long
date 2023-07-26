/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:15 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/26 11:29:38 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libs/libft/libft.h"
# include "../Libs/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define SIZE 64

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		rows;
	int		cols;
	int		colectables;
	int		gathered;
	int		valid;
	int		counter;
	t_point	player;
	t_point	exit;
	t_point	tile;
	t_img	img;
}	t_game;

t_game	*init(void);
char	**create_map(char *str);
void	free_array(char **map, int lines);
int		check_square(t_game *game);
int		check_walls(t_game *game);
int		count_dimensions(t_game *game);
int		character_check(t_game *game);
int		solong_strlen(char *str);
void	fill(char **map_cpy, t_game *game, int x, int y);
void	check_map(char *str, t_game *game);
int		check_elements(t_game *game);
int		number_lines(char *str);
int		count_exits(t_game *game);
void	render(t_game *game);
int		free_game(t_game *game);
void	put_square(t_game *game, char *address, int x, int y);
int		handle_keypress(int keysym, t_game *game);
int		handle_no_event(void *game);
void	walk_up(t_game *game);
void	move_up(t_game *game);
void	walk_down(t_game *game);
void	move_down(t_game *game);
void	walk_right(t_game *game);
void	move_right(t_game *game);
void	walk_left(t_game *game);
void	move_left(t_game *game);

#endif