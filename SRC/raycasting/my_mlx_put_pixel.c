/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_put_pixel.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 12:26:59 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/27 18:38:00 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"

#define UINT unsigned int

/**
 * @brief	Takes the refrence of the pixel of an image.
 * 			I then "fill" the pixel with the colour value.
 * 
 * @param img 
 * @param x 
 * @param y 
 * @param colour 
 * @return UINT 
 */
UINT	my_mlx_put_pixel(mlx_image_t *img, UINT x, UINT y, UINT colour)
{
	UINT	*pixel;

	pixel = (UINT *)&img->pixels[(x + y * img->width) * sizeof(UINT)];
	*pixel = colour;
	return (*pixel);
}
