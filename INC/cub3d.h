/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 18:58:48 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <stdbool.h>

# define SUCCES 0
# define ERROR 1

typedef struct s_vars
{
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

bool	is_cub_file_valid(char *argv[], t_vars *vars);

int		read_file(char *cub_file, t_vars *vars);

/*
	UTILS
*/

int		get_next_line(int fd, char **line);

/*
	ERROR
*/

void	non_fatal_error(char *msg);

void	fatal_perror(char *msg);

#endif