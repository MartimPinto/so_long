/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:11:22 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/14 13:15:59 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	render_window(t_game *game)
{
	int	width;
	int	height;

	width = game->cols * SIZE;
	height = game->rows * SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, width, height, 
		"so_long_bonus");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return ;
	}
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, width, height);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, 
			&game->img.bpp, &game->img.line_length, &game->img.endian);
}

void	render_border(t_game *game, int x, int y)
{
	if (y == 0 && x == 0)
		put_square(game, "./textures/Wall_Up_Left.xpm", x * SIZE, y * SIZE);
	if (y == 0 && x == game->cols - 1)
		put_square(game, "./textures/Wall_Up_Right.xpm", x * SIZE, y * SIZE);
	if (y == game->rows - 1 && x == 0)
		put_square(game, "./textures/Wall_Down_L.xpm", x * SIZE, y * SIZE);
	if (y == game->rows - 1 && x == game->cols - 1)
		put_square(game, "./textures/Wall_Down_R.xpm", x * SIZE, y * SIZE);
	if (y == 0 && (x > 0 && x < game->cols - 1))
		put_square(game, "./textures/Wall_Up.xpm", x * SIZE, y * SIZE);
	if ((y > 0 && y < game->rows - 1) && x == 0)
		put_square(game, "./textures/Wall_L.xpm", x * SIZE, y * SIZE);
	if ((y > 0 && y < game->rows - 1) && x == game->cols - 1)
		put_square(game, "./textures/Wall_R.xpm", x * SIZE, y * SIZE);
	if (y == game->rows - 1 && (x > 0 && x < game->cols - 1))
		put_square(game, "./textures/Wall_down.xpm", x * SIZE, y * SIZE);
	if ((y > 0 && y < game-> rows - 1) && (x > 0 && x < game->cols - 1))
		put_square(game, "./textures/Box_Wall.xpm", x * SIZE, y * SIZE);
}

void	render_elements(t_game *game, int x, int y, char c)
{
	if (c == '0')
		put_square(game, "./textures/Grass.xpm", x * SIZE, y * SIZE);
	if (c == 'P')
		put_square(game, "./textures/P_Idle.xpm", x * SIZE, y * SIZE);
	if (c == 'E')
		put_square(game, "./textures/Exit_1.xpm", x * SIZE, y * SIZE);
	if (c == 'C')
		put_square(game, "./textures/Collectable_1.xpm", x * SIZE, y * SIZE);
}

static void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				render_border(game, x, y);
			else
				render_elements(game, x, y, game->map[y][x]);
		}
	}
}

void	render(t_game *game)
{
	render_window(game);
	if (!game->win_ptr)
		return ;
	render_map(game);
	render_enemies(game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, 
		&free_game, game);
	mlx_loop(game->mlx_ptr);
}
