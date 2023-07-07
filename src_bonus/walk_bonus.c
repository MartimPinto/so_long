/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:01:20 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/07 18:51:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	walk_up(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y - 1;
	draw_walk_up(game, tile, grass);
	game->player.y = tile;
	if (game->map[tile][game->player.x] == 'C')
		collect_up(game);
	else
		idle_up(game, tile, grass);
}

void	walk_down(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.y;
	tile = game->player.y + 1;
	draw_walk_down(game, tile, grass);
	game->player.y = tile;
	if (game->map[tile][game->player.x] == 'C')
		collect_down(game);
	else
		idle_down(game, tile, grass);
}

void	walk_left(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x - 1;
	draw_walk_left(game, tile, grass);
	game->player.x = tile;
	if (game->map[game->player.y][tile] == 'C')
		collect_left(game);
	else
		idle_left(game, tile, grass);	
}

void	walk_right(t_game *game)
{
	int	tile;
	int	grass;

	grass = game->player.x;
	tile = game->player.x + 1;
	draw_walk_right(game, tile, grass);
	game->player.x = tile;
	if (game->map[game->player.y][tile] == 'C')
		collect_right(game);
	else
		idle_right(game, tile, grass);	
}
