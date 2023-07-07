/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_poses_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:21:17 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/07 17:51:25 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	idle_up(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/P_Up_1.xpm",
		game->player.x * SIZE, tile * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
	usleep(75000);
}

void	idle_down(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/P_Idle.xpm", 
		game->player.x * SIZE, tile * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
	usleep(75000);
}

void	idle_left(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/P_L_Idle.xpm",
		tile * SIZE, game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE,
		game->player.y * SIZE);
	usleep(75000);
}

void	idle_right(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/P_R_Idle.xpm",
		tile * SIZE, game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE,
		game->player.y * SIZE);
	usleep(75000);
}
