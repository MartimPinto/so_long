/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:40:38 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/14 11:26:25 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	solong_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	number_lines(char *str)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && i++ >= 0)
	{
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

void	put_square(t_game *game, char *address, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image(game->mlx_ptr, address, 
			&game->tile.x, &game->tile.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->img.mlx_img, x, y);
}

static int	moveability(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] == '0')
		return (0);
	if (game->map[y - 1][x] == '0')
		return (0);
	if (game->map[y][x + 1] == '0')
		return (0);
	if (game->map[y][x - 1] == '0')
		return (0);
	return (1);
}

void	enemy_pos(t_game *game, int moves)
{
	int	enemies;
	int	stuck;

	enemies = game->enemies;
	while (--enemies >= 0 && moves < game->counter)
	{
		while (moveability(game, game->enemy_x[enemies],
				game->enemy_y[enemies]))
		{
			enemies--;
			if (enemies < 0)
				return ;
		}
		stuck = game->enemy_x[enemies] + game->enemy_y[enemies];
		move_enemy(game, enemies);
		if (stuck == game->enemy_x[enemies] + game->enemy_y[enemies])
			enemies++;
	}
}
