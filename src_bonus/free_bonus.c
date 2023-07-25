/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:54:18 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/25 12:13:57 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free (map);
}

void	free_array(char **map, int lines)
{
	int	i;

	i = 0;
	while (i <= lines)
		free(map[i++]);
	free (map);
}

int	free_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->map)
		free_array(game->map, game->rows);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->enemy_x)
		free(game->enemy_x);
	if (game->enemy_y)
		free(game->enemy_y);
	free(game);
	exit (0);
}
