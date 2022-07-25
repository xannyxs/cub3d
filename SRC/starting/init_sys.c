/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_sys.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/22 12:59:38 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 19:09:30 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"

#include <math.h> /* Pi */

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

static void	load_png_path(t_path *path_data, t_textures *textures)
{
	textures->north_wall = mlx_load_png(path_data->north);
	if (!textures->north_wall)
		fatal_perror("mlx");
	textures->east_wall = mlx_load_png(path_data->east);
	if (!textures->east_wall)
		fatal_perror("mlx");
	textures->south_wall = mlx_load_png(path_data->south);
	if (!textures->south_wall)
		fatal_perror("mlx");
	textures->west_wall = mlx_load_png(path_data->west);
	if (!textures->west_wall)
		fatal_perror("mlx");
	free(path_data->north);
	free(path_data->east);
	free(path_data->south);
	free(path_data->west);
}

/*
	The MLX_image_to_window only needs to be called once,
	because of mlx_loop_hook(). It will be called automatically.
	Added a window limit. Otherwise it will slow the cub3d program too much.
*/
void	init_sys(t_vars *vars)
{
	set_values(vars);
	vars->textures.screen = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->textures.screen)
		fatal_perror("mlx");
	if (mlx_image_to_window(vars->mlx, vars->textures.screen, 0, 0) == -1)
		fatal_perror("mlx");
	mlx_set_window_limit(vars->mlx, WIDTH - 500, HEIGHT - 500, WIDTH, HEIGHT);
	load_png_path(&vars->path_data, &vars->textures);
}
