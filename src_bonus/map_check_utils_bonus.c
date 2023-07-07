/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:13:43 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/06 14:46:29 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	**create_map(char *str)
{
	char	**map;
	int		fd;
	int		i;
	int		j;

	i = number_lines(str);
	map = ft_calloc((i + 1), sizeof(char *));
	if (!map)
		return (NULL);
	j = -1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (++j < i)
	{
		map[j] = get_next_line(fd);
		if (!map[j])
		{
			free_array(map, i);
			close (fd);
			return (NULL);
		}
	}
	close(fd);
	return (map);
}

void	fill(char **map_cpy, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
		return ;
	if (map_cpy[y][x] == 'F' || map_cpy[y][x] == '1')
		return ;
	if (map_cpy[y][x] == 'C')
	{
		map_cpy[y][x] = 'F';
		game->gathered++;
	}
	else
		map_cpy[y][x] = 'F';
	fill(map_cpy, game, x - 1, y);
	fill(map_cpy, game, x + 1, y);
	fill(map_cpy, game, x, y - 1);
	fill(map_cpy, game, x, y + 1);
}

int	count_exits(t_game *game)
{
	int	y;
	int	x;
	int	exits;

	x = 0;
	y = 0;
	exits = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->exit.y = y;
				game->exit.x = x;
				exits++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (exits != 1)
		return (1);
	return (0);
}

int	check_elements(t_game *game)
{
	int	y;
	int	x;
	int	players;

	y = -1;
	players = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.y = y;
				game->player.x = x;
				players++;
			}
			else if (game->map[y][x] == 'C')
				game->colectables++;
			x++;
		}
	}
	if (game->colectables == 0 || players != 1)
		return (1);
	return (0);
}
