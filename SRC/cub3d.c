/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:36:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "error.h"
#include "libft.h"
#include "cub3d.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 256
#define HEIGHT 256

static void	hook(void *param)
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

int32_t	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		non_fatal_error(ARGC_ERROR);
		return (EXIT_FAILURE);
	}
	if (is_cub_file_valid(argv, &vars) == false)
		return (EXIT_FAILURE);
	vars.mlx = mlx_init(WIDTH, HEIGHT, "CUB3D of XVOORVAA", true);
	if (!vars.mlx)
		fatal_perror("malloc");
	vars.img = mlx_new_image(vars.mlx, 128, 128);
	ft_memset(vars.img->pixels, 255, vars.img->width * vars.img->height * sizeof(int));
	mlx_image_to_window(vars.mlx, vars.img, 0, 0);
	mlx_loop_hook(vars.mlx, &hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	return (EXIT_SUCCESS);
}
