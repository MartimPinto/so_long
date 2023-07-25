/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:01:32 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/25 12:18:09 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_enemies(t_game *game)
{
	int	enemy_index;
	int	x;
	int	y;

	enemy_index = 0;
	while (enemy_index < game->enemies)
	{
		x = game->enemy_x[enemy_index];
		y = game->enemy_y[enemy_index];
		put_square(game, "./textures/E_Idle_L.xpm", x * SIZE, y * SIZE);
		game->map[y][x] = 'G';
		enemy_index++;
	}
}
