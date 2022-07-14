/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_resize_window.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 14:47:27 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 14:49:23 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Checks if the window has been resized.
	if TRUE, it will send the new window size to the raycast function.

	There is a maximum & minimum of the window size.
*/
void	my_mlx_resize_window(mlx_t *mlx, t_data *data, mlx_image_t *screen)
{
	if ((int) data->screen_width != mlx->width || \
		(int) data->screen_height != mlx->height)
	{
		data->screen_width = mlx->width;
		data->screen_height = mlx->height;
		mlx_resize_image(screen, mlx->width, mlx->height);
	}
}