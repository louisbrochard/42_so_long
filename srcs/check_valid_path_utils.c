/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:16:05 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/27 10:16:07 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

void	get_utils_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
			j++;
		i++;
	}
	data->rows = i;
	data->cols = j;
}

void	get_start(char **map, t_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->rows)
	{
		while (col < data->cols)
		{
			if (map[row][col] == 'P')
			{
				data->start_row = row;
				data->start_col = col;
			}
			if (map[row][col] == 'E')
			{
				data->exit_found = 1;
			}
			col++;
		}
		col = 0;
		row++;
	}
}
