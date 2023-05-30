/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:20 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/30 16:05:57 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include <mlx.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_game
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;
}               t_complete;

// utils.c
void	*ft_memset(void *s, int c, size_t n);

// maps.c
int		ft_read_map(t_complete *game, char **argv);

// so_long.c
int		exit_point(t_complete *game);

// checker.c
void		check_errors(t_complete *game);

// gnl.c
char    *get_next_line(int fd);

// gnl_utils.c
size_t	ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);




#endif