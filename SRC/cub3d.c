/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 16:31:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "cub3d.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 256
#define HEIGHT 256

void	hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP))
		vars->img->instances[0].y -= 5;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN))
		vars->img->instances[0].y += 5;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
		vars->img->instances[0].x -= 5;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
		vars->img->instances[0].x += 5;
}

int32_t	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.img = mlx_new_image(vars.mlx, 128, 128);
	memset(vars.img->pixels, 255, vars.img->width * vars.img->height * sizeof(int));
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, &hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}