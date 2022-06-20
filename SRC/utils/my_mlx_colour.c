/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   my_mlx_colour.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:40:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/20 17:53:55 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	my_mlx_colour_put(mlx_texture_t *img, unsigned int x, unsigned int y)
{
	unsigned int	*colour;

	colour = (unsigned int *) img->pixels + (x + y * img->width) * sizeof(unsigned int);
	return (*colour);
}