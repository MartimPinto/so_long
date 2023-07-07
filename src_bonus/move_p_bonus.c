/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:42:46 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/07 18:47:20 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y - 1][p.x] == '1' || 
		(game->map[p.y - 1][p.x] == 'E' && game->colectables != game->gathered))
		return ;
	walk_up(game);
	if (game->map[p.y - 1][p.x] == 'C')
	{
		game->map[p.y - 1][p.x] = '0';
		game->gathered++;
	}
	game->counter++;
	ft_printf("Number of Moves: %d\n", game->counter);
	if (game->map[game->player.y][game->player.x] == 'E' && 
		game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	move_down(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y + 1][p.x] == '1' || 
		(game->map[p.y + 1][p.x] == 'E' && game->colectables != game->gathered))
		return ;
	walk_down(game);
	if (game->map[p.y + 1][p.x] == 'C')
	{
		game->map[p.y + 1][p.x] = '0';
		game->gathered++;
	}
	game->counter++;
	ft_printf("Number of Moves: %d\n", game->counter);
	if (game->map[game->player.y][game->player.x] == 'E' && 
		game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	move_left(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y][p.x - 1] == '1' || 
		(game->map[p.y][p.x - 1] == 'E' && game->colectables != game->gathered))
		return ;
	walk_left(game);
	if (game->map[p.y][p.x - 1] == 'C')
	{
		game->map[p.y][p.x - 1] = '0';
		game->gathered++;
	}
	game->counter++;
	ft_printf("Number of Moves: %d\n", game->counter);
	if (game->map[game->player.y][game->player.x] == 'E' && 
		game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}

void	move_right(t_game *game)
{
	t_point	p;

	p = game->player;
	if (game->map[p.y][p.x + 1] == '1' || 
		(game->map[p.y][p.x + 1] == 'E' && game->colectables != game->gathered))
		return ;
	walk_right(game);
	if (game->map[p.y][p.x + 1] == 'C')
	{
		game->map[p.y][p.x + 1] = '0';
		game->gathered++;
	}
	game->counter++;
	ft_printf("Number of Moves: %d\n", game->counter);
	if (game->map[game->player.y][game->player.x] == 'E' && 
		game->colectables == game->gathered)
	{
		ft_printf("Congratulations, you won!\n");
		free_game(game);
	}
}
