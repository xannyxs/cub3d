/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_get_colour.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:40:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/19 22:39:37 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

UINT	my_mlx_get_colour(mlx_texture_t *img, UINT x, UINT y)
{
	UINT	*colour;

	colour = (UINT *)(img->pixels + ((x + y * img->width) * sizeof(UINT)));
	return (*colour);
}
