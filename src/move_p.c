/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:42:46 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/26 11:25:37 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y - 1][p.x] == '1' || 
		(game->map[p.y - 1][p.x] == 'E' && game->colectables != game->gathered))
		return ;
	if (game->map[p.y - 1][p.x] == 'C')
	{
		game->map[p.y - 1][p.x] = '0';
		game->gathered++;
	}
	walk_up(game);
	game->counter++;
	ft_printf("\033[1;32mMoves:\033[0m %d\n", game->counter);
}

void	move_down(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y + 1][p.x] == '1' || 
		(game->map[p.y + 1][p.x] == 'E' && game->colectables != game->gathered))
		return ;
	if (game->map[p.y + 1][p.x] == 'C')
	{
		game->map[p.y + 1][p.x] = '0';
		game->gathered++;
	}
	walk_down(game);
	game->counter++;
	ft_printf("\033[1;32mMoves:\033[0m %d\n", game->counter);
}

void	move_left(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y][p.x - 1] == '1' || 
		(game->map[p.y][p.x - 1] == 'E' && game->colectables != game->gathered))
		return ;
	if (game->map[p.y][p.x - 1] == 'C')
	{
		game->map[p.y][p.x - 1] = '0';
		game->gathered++;
	}
	walk_left(game);
	game->counter++;
	ft_printf("\033[1;32mMoves:\033[0m %d\n", game->counter);
}

void	move_right(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y][p.x + 1] == '1' || 
		(game->map[p.y][p.x + 1] == 'E' && game->colectables != game->gathered))
		return ;
	if (game->map[p.y][p.x + 1] == 'C')
	{
		game->map[p.y][p.x + 1] = '0';
		game->gathered++;
	}
	walk_right(game);
	game->counter++;
	ft_printf("\033[1;32mMoves:\033[0m %d\n", game->counter);
}
