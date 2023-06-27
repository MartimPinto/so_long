/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:40:38 by mcarneir          #+#    #+#             */
/*   Updated: 2023/06/26 18:02:59 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	solong_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int	number_lines(char *str)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && i++ >= 0)
	{
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}