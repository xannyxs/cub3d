/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/16 22:26:56 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "error.h"
#include "libft.h"
#include "cub3d.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 1280
#define HEIGHT 1024

static void	hook(void *param)
{
	t_vars	*vars;

	vars = param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT))
	{
		vars->textures.north_wall->instances[0].x -= 5;
		vars->textures.west_wall->instances[0].x -= 5;
		// vars->textures.east_wall->instances[0].x -= 5;
		// vars->textures.south_wall->instances[0].x -= 5;
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT))
	{
		vars->textures.north_wall->instances[0].x += 5;
		vars->textures.west_wall->instances[0].x += 5;
		// vars->textures.east_wall->instances[0].x += 5;
		// vars->textures.south_wall->instances[0].x += 5;
	}
}

static void	create_wall(mlx_t **mlx, mlx_image_t **wall, int32_t x, int32_t y, uint32_t colour)
{
	*wall = mlx_new_image(*mlx, 720, 128);
	for (int i = 0; i < 720; i++)
		for (int j = 0; j < 128; j++)
			mlx_put_pixel(*wall, i, j, colour);
	mlx_image_to_window(*mlx, *wall, x, y);
}

int32_t	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		non_fatal_error(ARGC_ERROR);
		return (ERROR);
	}
	if (is_cub_file_valid(argv[1], &vars) == false)
		return (ERROR);
	vars.mlx = mlx_init(WIDTH, HEIGHT, "Cherries & Crabs", false);
	if (!vars.mlx)
		fatal_perror("mlx");
	create_wall(&vars.mlx, &vars.textures.north_wall, 0, 128, 0xFF00FF);
	create_wall(&vars.mlx, &vars.textures.west_wall, 720, 128, 0xFF000F);
	mlx_loop_hook(vars.mlx, &hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.map_grid);
	return (EXIT_SUCCESS);
}
