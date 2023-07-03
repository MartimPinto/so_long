/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:55:23 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/03 17:03:29 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(char *str)
{
	int		fd;
	char	*ber;

	ber = ".ber";
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		close(fd);
		return (1);
	}
	str = ft_strrchr(str, '.');
	if (!str)
	{
		ft_printf("Error: Invalid file found\n");
		return (1);
	}
	if (ft_strncmp(str, ber, 4) != 0)
	{
		ft_printf("Error: Invalid file type\n");
		return (1);
	}
	close (fd);
	return (0);

}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
		char	*dst;
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2 || check_file(argv[1]) != 0)
		return (1);
	game = init();
	check_map(argv[1], game);
	if (!game->map || game->valid != 0)
	{
		free_array(game->map, game->rows);
		return (1);
	}
	render(game);
	free_game(game);
}
