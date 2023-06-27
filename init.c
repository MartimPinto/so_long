/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:20:24 by mcarneir          #+#    #+#             */
/*   Updated: 2023/06/27 16:14:31 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->rows = 0;
	game->cols = 0;
	game->colectables = 0;
	game->player.y = 0;
	game->player.x = 0;
	game->exit.y = 0;
	game->exit.x = 0;
	game->gathered = 0;
	return (game);
}
