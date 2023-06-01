/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 09:17:28 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/06/01 09:19:11 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

# include "so_long.h"

void    *mlx_init();


void   *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

//int     mlx_clear_window(void *mlx_ptr, void *win_ptr);
//int     mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

#endif