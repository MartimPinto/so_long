/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:36:57 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/14 14:49:38 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	quit_animation(t_game *game)
{
	put_square(game, "./textures/Quit_1.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Quit_2.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Quit_3.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Quit_4.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
	put_square(game, "./textures/Quit_5.xpm", game->player.x * SIZE,
		game->player.y * SIZE);
	usleep(100000);
}