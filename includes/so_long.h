/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:21:20 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/19 16:46:54 by lbrochar         ###   ########.fr       */
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
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include "../minilibx-linux/mlx.h"

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
}				t_complete;

// utils.c
void	*ft_memset(void *s, int c, size_t n);

// maps.c
int		ft_read_map(t_complete *game, char **argv);

// so_long.c
int		exit_point(t_complete *game);

// checker.c
void	check_errors(t_complete *game);

// graphics.c
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
void	place_collectable(t_complete *game, int height, int width);
void	place_player(t_complete *game, int height, int width);

// gnl.c
char	*get_next_line(int fd);

//move.c
int	controls_working(int command, t_complete *game);


// gnl_utils.c
size_t	ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);

#endif
