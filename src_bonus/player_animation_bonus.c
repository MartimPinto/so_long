/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:41:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/26 11:17:08 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_walk_up(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/Grass.xpm", game->player.x * SIZE, 
		grass * SIZE);
	put_square(game, "./textures/P_Up_1.xpm", game->player.x * SIZE, 
		tile * SIZE + ((SIZE / 4) * 3));
	put_square(game, "./textures/Grass.xpm", game->player.x * SIZE, 
		grass * SIZE);
	usleep(70000);
	put_square(game, "./textures/P_Up_2.xpm", game->player.x * SIZE, 
		tile * SIZE + ((SIZE / 4) * 2));
	put_square(game, "./textures/Grass.xpm", game->player.x * SIZE, 
		grass * SIZE);
	usleep(60000);
	put_square(game, "./textures/P_Up_3.xpm", game->player.x * SIZE, 
		tile * SIZE + (SIZE / 4));
	put_square(game, "./textures/Grass.xpm", game->player.x * SIZE, 
		grass * SIZE);
}

void	draw_walk_down(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
	put_square(game, "./textures/P_Idle.xpm", 
		game->player.x * SIZE, tile * SIZE - ((SIZE / 4) * 3));
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
	usleep(70000);
	put_square(game, "./textures/P_down_1.xpm", 
		game->player.x * SIZE, tile * SIZE - (SIZE / 4) * 2);
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
	usleep(60000);
	put_square(game, "./textures/P_down_2.xpm", 
		game->player.x * SIZE, tile * SIZE - (SIZE / 4));
	put_square(game, "./textures/Grass.xpm", 
		game->player.x * SIZE, grass * SIZE);
}

void	draw_walk_left(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
	put_square(game, "./textures/P_Left_1.xpm", 
		tile * SIZE + ((SIZE / 4) * 3), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
	usleep(70000);
	put_square(game, "./textures/P_Left_2.xpm", 
		tile * SIZE + ((SIZE / 4) * 2), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
	usleep(60000);
	put_square(game, "./textures/P_Left_3.xpm", 
		tile * SIZE + (SIZE / 4), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
}

void	draw_walk_right(t_game *game, int tile, int grass)
{
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
	put_square(game, "./textures/P_Right_1.xpm", 
		tile * SIZE - ((SIZE / 4) * 3), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->player.y * SIZE);
	usleep(70000);
	put_square(game, "./textures/P_Right_2.xpm", 
		tile * SIZE - ((SIZE / 4) * 2), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", 
		grass * SIZE, game->player.y * SIZE);
	usleep(60000);
	put_square(game, "./textures/P_Right_3.xpm", 
		tile * SIZE - (SIZE / 4), game->player.y * SIZE);
	put_square(game, "./textures/Grass.xpm", grass * SIZE, 
		game->player.y * SIZE);
}

void	death_animation(t_game *game)
{
	put_square(game, "./textures/Death_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(500000);
	put_square(game, "./textures/Death_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(450000);
	put_square(game, "./textures/Death_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(300000);
	ft_printf("\033[1;31mGAME OVER\033[0m\n");
	free_game(game);
}
