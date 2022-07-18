/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:21:04 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/18 17:16:23 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "MLX42/MLX42.h"
#include "error.h" /* Error messages */
#include "libft.h" /* ft_free_array */

#include <stdio.h>
#include <math.h>

static void	set_values(t_vars *vars)
{
	vars->data.dir_x = -1;
	vars->data.dir_y = 0;
	vars->data.plane_x = 0;
	vars->data.plane_y = 0.66;
	find_player(vars);
	if (vars->data.player_char == 'N')
		rotate(&vars->data, M_PI / 2);
	else if (vars->data.player_char == 'S')
		rotate(&vars->data, M_PI * 1.5);
	else if (vars->data.player_char == 'W')
		rotate(&vars->data, M_PI);
}

/*
	The MLX_image_to_window only needs to be called once,
	because of mlx_loop_hook(). It will be called automatically.
	Added a window limit. Otherwise it will slow the cub3d program too much.
*/
static void	init_sys(t_vars *vars)
{
	set_values(vars);
	vars->textures.screen = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->textures.screen)
		fatal_perror("mlx");
	if (mlx_image_to_window(vars->mlx, vars->textures.screen, 0, 0) == -1)
		fatal_perror("mlx");
	mlx_set_window_limit(vars->mlx, WIDTH - 500, HEIGHT - 500, WIDTH, HEIGHT);

	// Get rid of these last four lines when @Swenne is done with loading .pngs
	vars->textures.north_wall = mlx_load_png("IMG/Wolfenstein/bluestone.png");
	vars->textures.east_wall = mlx_load_png("IMG/Wolfenstein/greystone.png");
	vars->textures.south_wall = mlx_load_png("IMG/Wolfenstein/purplestone.png");
	vars->textures.west_wall = mlx_load_png("IMG/Wolfenstein/eagle.png");
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
	vars.mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!vars.mlx)
		fatal_perror("mlx");
	if (is_monitor_valid(vars.mlx) == false)
		return (ERROR);
	init_sys(&vars);
	mlx_loop_hook(vars.mlx, &raycasting_hook, &vars);
	mlx_loop_hook(vars.mlx, &movement_hook, &vars);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
	ft_free_array(vars.map_data.world_map);
	return (EXIT_SUCCESS);
}
