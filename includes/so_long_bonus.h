/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:33:38 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/13 16:51:20 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libs/libft/libft.h"
# include "../Libs/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

# define SIZE 64

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_img;


typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef	struct	s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int	rows;
	int	cols;
	int	colectables;
	int	gathered;
	int	valid;
	int	counter;
	int	enemies;
	int	*enemy_x;
	int	*enemy_y;
	t_point	player;
	t_point	exit;
	t_point tile;
	t_img	img;
}	t_game;

t_game	*init(void);
char	**create_map(char *str);
void	free_array(char **map, int lines);
int	check_square(t_game *game);
int	check_walls(t_game *game);
int	count_dimensions(t_game *game);
int	solong_strlen(char *str);
void	fill(char **map_cpy, t_game *game, int x, int y);
void	check_map(char *str, t_game *game);
int	check_elements(t_game *game);
int	number_lines(char *str);
int	count_exits(t_game *game);
void	render(t_game *game);
int	free_game(t_game *game);
void	put_square(t_game *game, char *address, int x, int y);
int	handle_keypress(int keysym, t_game *game);
int	handle_no_event(void *game);

/*Movement*/

void	walk_up(t_game *game);
void	move_up (t_game *game);
void	idle_up(t_game *game, int tile, int grass);
void	collect_up(t_game *game);
void	draw_walk_up(t_game *game, int tile, int grass);
void	walk_down(t_game *game);
void	move_down(t_game *game);
void	idle_down(t_game *game, int tile, int grass);
void	collect_down(t_game *game);
void	draw_walk_down(t_game *game, int tile, int grass);
void	walk_right(t_game *game);
void	move_right(t_game *game);
void	idle_right(t_game *game, int tile, int grass);
void	collect_right(t_game *game);
void	draw_walk_right(t_game *game, int tile, int grass);
void	walk_left(t_game *game);
void	move_left(t_game *game);
void	idle_left(t_game *game, int tile, int grass);
void	collect_left(t_game *game);
void	draw_walk_left(t_game *game, int tile, int grass);

/*Enemies*/

int	init_enemies(t_game *game);
void	render_enemies(t_game *game);
void	move_enemy(t_game *game, int enemies);
void	enemy_atk_up(t_game *game, int enemies);
void	enemy_atk_down(t_game *game, int enemies);
void	enemy_atk_left(t_game *game, int enemies);
void	enemy_atk_right(t_game *game, int enemies);
void	enemy_pos(t_game *game, int moves);
void	enemy_idle(t_game *game, int enemies);

#endif