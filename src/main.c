/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:55:23 by mcarneir          #+#    #+#             */
/*   Updated: 2023/07/26 11:27:38 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		free_game(game);
	if (keysym == XK_Up || keysym == XK_w)
		move_up(game);
	if (keysym == XK_Down || keysym == XK_s)
		move_down(game);
	if (keysym == XK_Left || keysym == XK_a)
		move_left(game);
	if (keysym == XK_Right || keysym == XK_d)
		move_right(game);
	return (0);
}

int	handle_no_event(void *game)
{
	(void)game;
	return (0);
}

static int	check_file(char *str)
{
	int		fd;
	char	*ber;

	ber = ".ber";
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[1;31mError\033[0m\n");
		close(fd);
		return (1);
	}
	str = ft_strrchr(str, '.');
	if (!str)
	{
		ft_printf("\033[1;31mError\033[0m\n");
		return (1);
	}
	if (ft_strncmp(str, ber, 4) != 0)
	{
		ft_printf("\033[1;31mError\033[0m\n");
		return (1);
	}
	close (fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || check_file(argv[1]) != 0)
		return (1);
	game = init();
	check_map(argv[1], game);
	if (!game->map || game->valid != 0)
		free_game(game);
	render(game);
	free_game(game);
}
