/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_Idle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:48:53 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/13 16:50:53 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_idle(t_game *game, int enemies)
{
	put_square(game, "./textures/E_Idle_L.xpm", 
		game->enemy_x[enemies] * SIZE, game->enemy_y[enemies] * SIZE);
}