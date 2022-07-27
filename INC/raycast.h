/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 13:50:40 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/27 18:03:11 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# define UINT unsigned int

enum e_side
{
	EW,
	NS
};

/*
	All raytracing data.
*/
typedef struct s_data
{
	char			player_char;
	UINT			screen_width;
	UINT			screen_height;
	int				map_x;
	int				map_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				step_x;
	int				step_y;
	int				tex_x;
	int				tex_y;
	int				tex_num;
	int				tex_width;
	int				tex_height;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			tex_pos;
	double			wall_x;
	double			step;
}	t_data;

#endif