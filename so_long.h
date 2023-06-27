/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:30:15 by mcarneir          #+#    #+#             */
/*   Updated: 2023/06/27 17:06:56 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libs/libft/libft.h"
# include "Libs/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef	struct	s_game
{
	char	**map;
	int	rows;
	int	cols;
	int	colectables;
	int	gathered;
	t_point	player;
	t_point	exit;
}	t_game;

t_game	*init(void);
char	**create_map(char *str);
//void	free_map(char **map);
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


#endif