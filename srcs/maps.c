/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:28:03 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/19 17:47:38 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
		return (0);
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	ft_read_map(t_complete *game, char **argv)
{
	char	*line;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		exit(0);
	while (1)
	{
		line = get_next_line(game->fd);
		if (!add_line(game, line))
			break ;
	}
	close (game->fd);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}
