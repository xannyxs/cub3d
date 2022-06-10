/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/10 14:24:17 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "error.h" /* Error messages */
#include "libft.h" /* ft_free_array */

#include <stdlib.h> /* Malloc */

static void	set_values(t_data *data)
{
	data->pos_x = 5;
	data->pos_y = 5;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = false;
}

/*
	The MLX_image_to_window only needs to be called once,
	because of mlx_loop_hook. It will be called automaticlly.
*/
static void	init_sys(t_vars *vars)
{
	vars->data = ft_malloc(sizeof(t_data));
	set_values(vars->data);
	vars->textures.screen = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars->mlx, vars->textures.screen, 150, 150);
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
	vars.mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!vars.mlx)
		fatal_perror("mlx");
	init_sys(&vars);
	mlx_loop_hook(vars.mlx, &raycasting_hook, &vars);
	mlx_loop_hook(vars.mlx, &draw_hook, &vars);
	mlx_loop_hook(vars.mlx, &movement_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.world_map);
	return (EXIT_SUCCESS);
}
