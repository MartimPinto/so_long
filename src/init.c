/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:20:24 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/06 12:53:02 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_game *game)
{
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_length = 0;
	game->img.endian = 0;
}

void	init_game(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->colectables = 0;
	game->player.y = 0;
	game->player.x = 0;
	game->exit.y = 0;
	game->exit.x = 0;
	game->gathered = 0;
	game->valid = 0;
	game->counter = 0;
}

t_game	*init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->tile.x = SIZE;
	game->tile.y = SIZE;
	init_img(game);
	init_game(game);
	game->mlx_ptr = mlx_init();
	return (game);
}
