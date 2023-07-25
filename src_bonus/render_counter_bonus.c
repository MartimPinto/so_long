/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_counter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:02:44 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/25 12:21:07 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_moves_counter(t_game *game)
{
	char	*moves;
	int		x;
	int		y;

	x = game->cols / 2;
	y = game->rows;
	put_square(game, "./textures/Black.xpm", x * SIZE, y * SIZE);
	put_square(game, "./textures/Black.xpm", (x + 1) * SIZE, y * SIZE);
	moves = ft_itoa(game->counter);
	x = (game->cols / 2) * SIZE;
	y = game->rows * SIZE + 32;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 42, y, 0x0000FF00, moves);
	free (moves);
}
