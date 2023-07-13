/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:02:50 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/13 17:14:57 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_calloc(t_game *game)
{
	if(!game->enemy_x || !game->enemy_y)
	{
		if(game->enemy_x)
			free(game->enemy_x);
		if (game->enemy_y)
			free(game->enemy_y);
		return (1);
	}
	return (0);
}

static int	count_floor(t_game *game)
{
	int	floor;
	int	x;
	int	y;

	floor = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
				floor++;
		}
	}
	return (floor);
}

int	init_enemies(t_game *game)
{
	int	x;
	int	y;
	int	enemies;

	enemies = count_floor(game) / 20;
	game->enemies = enemies;
	game->enemy_x = ft_calloc(enemies, sizeof(int));
	game->enemy_y = ft_calloc(enemies, sizeof(int));
	if(check_calloc(game))
		return (1);
	while (--enemies >= 0)
	{
		y = 0;
		x = 0;
		
		while (game->map[y][x] != '0')
		{
			y = rand() % (game->rows - 1);
			x = rand() % (game->cols - 1);
		}
		game->enemy_y[enemies] = y;
		game->enemy_x[enemies] = x;
	}
	return (0);
}