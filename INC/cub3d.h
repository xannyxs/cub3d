/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/15 19:11:28 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <stdbool.h>

# define SUCCES 0
# define ERROR 1

typedef struct	s_map
{
	char				**map_grid;
	unsigned int		width;
	unsigned int		height;
}	t_map;

typedef struct	s_vars
{
	t_map		map_data;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_vars;

/*
	CUB3D
*/

int32_t	main(int argc, char *argv[]);

/*
	FILE CHECK
*/

bool	is_cub_file_valid(char *cub_file, t_vars *vars);

int		read_file(char *cub_file, t_vars *vars);

int		check_map(t_map *map_data);

/*
	UTILS
*/

int		get_next_line(int fd, char **line);

/*
	ERROR
*/

void	non_fatal_error(char *msg);

void	fatal_perror(char *msg);

/*
	WRAPPED
*/

int		open_fd(char *cub_file);

#endif
