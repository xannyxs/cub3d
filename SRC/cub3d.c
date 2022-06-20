/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/20 17:36:37 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "error.h" /* Error messages */
#include "libft.h" /* ft_free_array */

static void	set_values(t_vars *vars)
{
	find_player(vars);
	vars->data.dir_x = -1;
	vars->data.dir_y = 0;
	vars->data.plane_x = 0;
	vars->data.plane_y = 0.66;
}

/*
	The MLX_image_to_window only needs to be called once,
	because of mlx_loop_hook(). It will be called automatically.
*/
static void	init_sys(t_vars *vars)
{
	set_values(vars);
	vars->textures.screen = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(vars->mlx, vars->textures.screen, 0, 0);
	vars->textures.north_wall = mlx_load_xpm42("IMG/XPM42/bluestone.xpm42");
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
	mlx_loop_hook(vars.mlx, &movement_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.world_map);
	return (EXIT_SUCCESS);
}
