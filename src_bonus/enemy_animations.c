/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:37:39 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/14 14:12:05 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_atk_up(t_game *game, int enemies)
{
	int	grass;

	grass = game->enemy_y[enemies];
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	game->enemy_y[enemies] -= 1;
	put_square(game, "./textures/E_Atk1_L.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE + ((SIZE / 3) * 2));
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Atk2_L.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE + (SIZE / 3));
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Idle_R.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
}

void	enemy_atk_down(t_game *game, int enemies)
{
	int grass;

	grass = game->enemy_y[enemies];
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	game->enemy_y[enemies] += 1;
	put_square(game, "./textures/E_Atk1_R.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE - ((SIZE / 3) * 2));
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Atk2_R.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE - (SIZE / 3));
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Idle_L.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		game->enemy_x[enemies] * SIZE, grass * SIZE);
}

void	enemy_atk_left(t_game *game, int enemies)
{
	int	grass;

	grass = game->enemy_x[enemies];
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	game->enemy_x[enemies] -= 1;
	put_square(game, "./textures/E_Atk1_L.xpm", 
		game->enemy_x[enemies] * SIZE + ((SIZE / 3) * 2), game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Atk2_L.xpm", 
		game->enemy_x[enemies] * SIZE + (SIZE / 3), game->enemy_y[enemies]* SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Idle_L.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
}

void	enemy_atk_right(t_game *game, int enemies)
{
	int	grass;
	
	grass = game->enemy_x[enemies];
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	game->enemy_x[enemies] += 1;
	put_square(game, "./textures/E_Atk1_R.xpm", 
		game->enemy_x[enemies] * SIZE - ((SIZE / 3) * 2), game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Atk2_R.xpm", 
		game->enemy_x[enemies] * SIZE - (SIZE / 3), game->enemy_y[enemies]* SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
	usleep(30000);
	put_square(game, "./textures/E_Idle_R.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->enemy_y[enemies] * SIZE);
}
