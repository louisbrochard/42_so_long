/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:01:53 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/29 10:15:05 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	can_reach_exit(char **map, int row, int col, t_data *data)
{
	if (row < 0 || row >= data->rows || col < 0 || col >= data->cols
		|| map[row][col] == '1')
		return (0);
	if (map[row][col] == 'E')
		return (1);
	map[row][col] = '1';
	if (can_reach_exit(map, row - 1, col, data))
		return (1);
	if (can_reach_exit(map, row + 1, col, data))
		return (1);
	if (can_reach_exit(map, row, col - 1, data))
		return (1);
	if (can_reach_exit(map, row, col + 1, data))
		return (1);
	return (0);
}

int	is_valid_path_to_exit(char **map, t_data *data)
{
	int	row;

	row = 0;
	get_start(map, data);
	if (!(data->exit_found) || data->start_row == -1 || data->start_col == -1)
		return (0);
	row = can_reach_exit(map, data->start_row, data->start_col,
			data);
	return (row);
}

int	can_reach_collectibles(char **map, int row, int col, t_data *data)
{
	if (row < 0 || row >= data->rows || col < 0 || col >= data->cols
		|| map[row][col] == '1')
		return (0);
	if (map[row][col] == 'C')
		map[row][col] = 'V';
	map[row][col] = '1';
	if (can_reach_collectibles(map, row - 1, col, data))
		return (1);
	if (can_reach_collectibles(map, row + 1, col, data))
		return (1);
	if (can_reach_collectibles(map, row, col - 1, data))
		return (1);
	if (can_reach_collectibles(map, row, col + 1, data))
		return (1);
	return (0);
}

int	is_valid_path_to_collectibles(char **map, t_data *data)
{
	int	row;
	int	i;
	int	j;

	i = 0;
	j = 0;
	row = 0;
	if (!(data->exit_found) || data->start_row == -1 || data->start_col == -1)
		return (0);
	row = can_reach_collectibles(map, data->start_row, data->start_col,
			data);
	while (i < data->rows)
	{
		while (j < data->cols)
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (row);
}

int	check_valid_path(t_data *data)
{
	char	**map_copy;
	char	**map_copy2;
	int		i;

	i = 0;
	get_utils_path(data);
	map_copy = ft_arrdup(data->map);
	map_copy2 = ft_arrdup(data->map);
	if (!is_valid_path_to_exit(map_copy, data))
	{
		ft_printf("Aucun chemin n'est possible pour aller du P à l'E.\n");
		i = 1;
	}
	if (is_valid_path_to_collectibles(map_copy2, data) != 0)
	{
		ft_printf("Aucun chemin n'est possible pour aller du P à tous les C.\n");
		i = 1;
	}
	ft_freemap(data, map_copy);
	ft_freemap(data, map_copy2);
	return (i);
}
