/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:03:12 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/25 12:22:54 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_enemy_up(t_game *game, int *x, int *y, int enemies)
{
	if (game->map[y[enemies] - 1][x[enemies]] == '1'
		|| game->map[y[enemies] - 1][x[enemies]] == 'C'
		|| game->map[y[enemies] - 1][x[enemies]] == 'E'
		|| game->map[y[enemies] - 1][x[enemies]] == 'G')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_atk_up(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'G';
}

void	move_enemy_down(t_game *game, int *x, int *y, int enemies)
{
	if (game->map[y[enemies] + 1][x[enemies]] == '1'
		|| game->map[y[enemies] + 1][x[enemies]] == 'C'
		|| game->map[y[enemies] + 1][x[enemies]] == 'E'
		|| game->map[y[enemies] + 1][x[enemies]] == 'G')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_atk_down(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'G';
}

void	move_enemy_left(t_game *game, int *x, int *y, int enemies)
{
	if (game->map[y[enemies]][x[enemies] - 1] == '1'
		|| game->map[y[enemies]][x[enemies] - 1] == 'C'
		|| game->map[y[enemies]][x[enemies] - 1] == 'E'
		|| game->map[y[enemies]][x[enemies] - 1] == 'G')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_atk_left(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'G';
}

void	move_enemy_right(t_game *game, int *x, int *y, int enemies)
{
	if (game->map[y[enemies]][x[enemies] + 1] == '1'
		|| game->map[y[enemies]][x[enemies] + 1] == 'C'
		|| game->map[y[enemies]][x[enemies] + 1] == 'E'
		|| game->map[y[enemies]][x[enemies] + 1] == 'G')
		return ;
	game->map[y[enemies]][x[enemies]] = '0';
	enemy_atk_right(game, enemies);
	game->map[y[enemies]][x[enemies]] = 'G';
}

void	move_enemy(t_game *game, int enemies)
{
	int	*x;
	int	*y;
	int	n;

	x = game->enemy_x;
	y = game->enemy_y;
	n = rand() % 4 + 1;
	if (n == 1)
		move_enemy_up(game, x, y, enemies);
	if (n == 2)
		move_enemy_down(game, x, y, enemies);
	if (n == 3)
		move_enemy_left(game, x, y, enemies);
	if (n == 4)
		move_enemy_right(game, x, y, enemies);
	if (x[enemies] == game->player.x && y[enemies] == game->player.y)
		death_animation(game);
}
