/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:28:14 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/26 11:27:16 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_dimensions(t_game *game)
{
	int	rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (game->map[rows] != NULL)
		rows++;
	if (rows > 0)
		cols = solong_strlen(game->map[0]);
	game->rows = rows;
	game->cols = cols;
	if (cols < 5 || rows < 3)
		return (1);
	return (0);
}

int	check_square(t_game *game)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (solong_strlen(game->map[0]) != solong_strlen(game->map[y]))
			return (1);
		y++;
	}
	return (0);
}

int	check_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		while (game->map[y][x] != '\n' && y == 0)
		{
			if (!(game->map[0][x] == '1')
				|| !(game->map[game->rows - 1][x] == '1'))
				return (1);
			x++;
		}
		if (!(game->map[y][0] == '1') || !(game->map[y][game->cols - 1] == '1'))
			return (1);
		y++;
	}
	return (0);
}

int	path_check(char *str, t_game *game)
{
	char	**map_cpy;

	map_cpy = create_map(str);
	if (!map_cpy)
		return (1);
	fill(map_cpy, game, game->player.x, game->player.y);
	if (!game->exit.y || !game->exit.x)
	{
		free_array(map_cpy, game->rows);
		return (1);
	}
	if (map_cpy[game->exit.y][game->exit.x] != 'F')
	{
		free_array(map_cpy, game->rows);
		return (1);
	}
	if (game->colectables != game->gathered)
	{
		free_array(map_cpy, game->rows);
		return (1);
	}
	free_array(map_cpy, game->rows);
	game->gathered = 0;
	return (0);
}

void	check_map(char *str, t_game *game)
{
	int	check;

	check = 0;
	game->map = create_map(str);
	if (!game->map)
	{
		ft_printf("\033[1;31mError\033[0m\n");
		ft_printf("Invalid Map!\n");
		return ;
	}
	check += count_dimensions(game) + check_square(game) + count_exits(game);
	check += check_elements(game) + character_check(game) + check_walls(game);
	if (check == 0)
		check += path_check(str, game);
	if (check != 0)
	{
		ft_printf("\033[1;31mError\033[0m\n");
		ft_printf("Invalid Map!\n");
		game->valid++;
	}
}
