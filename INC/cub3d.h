/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/16 21:46:56 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <stddef.h>

# define SUCCES 0
# define ERROR 1

typedef struct	s_node
{
	char 			*content;
	struct s_node	*next;
}	t_node;

typedef struct	s_textures
{
	mlx_image_t	*north_wall;
	mlx_image_t	*west_wall;
	mlx_image_t	*east_wall;
	mlx_image_t	*south_wall;
}	t_textures;

typedef struct	s_map
{
	char				**map_grid;
	unsigned int		width;
	unsigned int		height;
}	t_map;

typedef struct	s_vars
{
	t_map		map_data;
	t_textures	textures;
	mlx_t		*mlx;
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
	WRAPPED
*/

int		ft_open(char *cub_file);

void	*ft_malloc(size_t size);

/*
	LINKED LIST
*/

void			new_node(t_node **head, char *content);

void			ft_free_list(t_node **head);

size_t			ft_lstlen(t_node *head);

#endif
