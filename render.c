/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:11:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/03 19:07:20 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_window(t_game *game)
{
	int	width;
	int	height;
	
	width = game->cols * SIZE;
	height = game->rows * SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, "so_long");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return ;
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, width, height);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	mlx_loop(game->mlx_ptr);
}

void	put_square(t_game *game, char *address, int x, int y)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	mlx_xpm_file_to_image(game->mlx_ptr, address, (int *)64, (int *)64);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, 
		game->img.mlx_img, x, y);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;

	while (game->map[y])
	{
		while(game->map[y][x] != '\n' || game->map[y][x] != '\0')
		{
			if (y == 0 && x == 0)
				put_square(game, "./textures/XPM/Wall_Up_Left.xpm", x * SIZE, y * SIZE);
		}
	}
}

void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
		return ;
	render_map(game);
}	