/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:01:20 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/04 17:15:20 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walk_up(t_game *game)
{
	int	tile;

	tile = game->player.y;
	put_square(game, "./textures/XPM/Grass.xpm", game->player.x * SIZE, tile * SIZE);
	tile = game->player.y - 1;
	put_square(game, "./textures/XPM/P_Up_1.xpm", game->player.x * SIZE, tile * SIZE);
	game->player.y = tile;
	if (game->map[tile][game->player.x] == 'E' && game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	walk_down(t_game *game)
{
	int	tile;

	tile = game->player.y;
	put_square(game, "./textures/XPM/Grass.xpm", game->player.x * SIZE, tile * SIZE);
	tile = game->player.y + 1;
	put_square(game, "./textures/XPM/P_down_1.xpm", game->player.x * SIZE, tile * SIZE);
	game->player.y = tile;
	if (game->map[tile][game->player.x] == 'E' && game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	walk_left(t_game *game)
{
	int	tile;

	tile = game->player.x;
	put_square(game, "./textures/XPM/Grass.xpm", tile * SIZE, game->player.y * SIZE);
	tile = game->player.x - 1;
	put_square(game, "./textures/XPM/P_Left_1.xpm", tile * SIZE, game->player.y * SIZE);
	game->player.x = tile;
	if (game->map[game->player.y][tile] == 'E' && game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	walk_right(t_game *game)
{
	int	tile;

	tile = game->player.x;
	put_square(game, "./textures/XPM/Grass.xpm", tile * SIZE, game->player.y * SIZE);
	tile = game->player.x + 1;
	put_square(game, "./textures/XPM/P_Right_1.xpm", tile * SIZE, game->player.y * SIZE);
	game->player.x = tile;
	if (game->map[game->player.y][tile] == 'E' && game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}