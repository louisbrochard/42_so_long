/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:54:15 by lbrochar          #+#    #+#             */
/*   Updated: 2023/06/20 16:06:33 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_charcpt(char *str, char chr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == chr)
			ret++;
		i++;
	}
	return (ret);
}

static int	ft_strnchr(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		y;
	int		cpt;
	char	**ret;

	i = 0;
	y = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_charcpt(str, sep) + 1));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		cpt = ft_strnchr(&str[i], sep);
		ret[y] = ft_strncpy(&str[i], cpt);
		if (str[i + cpt] != '\0')
			i += (cpt + 1);
		else
			i += cpt;
		y++;
	}
	ret[y] = NULL;
	free(str);
	return (ret);
}
