/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_get_colour.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:40:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 17:23:37 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"

#define UINT unsigned int

UINT	my_mlx_get_colour(mlx_texture_t *img, UINT x, UINT y)
{
	UINT	*colour;

	colour = (UINT *)(img->pixels + ((x + y * img->width) * sizeof(UINT)));
	return (*colour);
}
