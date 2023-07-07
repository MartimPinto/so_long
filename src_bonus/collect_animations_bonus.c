/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_animations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:11:31 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/07 18:43:28 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	collect_up(t_game *game)
{
	put_square(game, "./textures/Col_U_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_U_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_U_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/P_Up_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
}


void	collect_down(t_game *game)
{
	put_square(game, "./textures/Col_D_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_D_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_D_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/P_Idle.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
}

void	collect_left(t_game *game)
{
	put_square(game, "./textures/Col_L_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_L_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_L_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/P_L_Idle.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
}

void	collect_right(t_game *game)
{
	put_square(game, "./textures/Col_R_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_R_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Col_R_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/P_R_Idle.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
}
