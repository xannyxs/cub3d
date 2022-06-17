/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/17 15:17:35 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "raycast.h"

# include <stdbool.h>
# include <stddef.h>

# define SUCCES 0
# define ERROR 1

# define WIDTH 1280
# define HEIGHT 1024

/*
	Needed to get the file lines.
*/
typedef struct	s_node
{
	char 			*content;
	struct s_node	*next;
}	t_node;

// Testing...
typedef struct	s_textures
{
	mlx_image_t	*screen;
	mlx_image_t	*north_wall;
	mlx_image_t	*west_wall;
	mlx_image_t	*east_wall;
	mlx_image_t	*south_wall;
}	t_textures;

/*
	All the map data in one struct.
*/
typedef struct	s_map
{
	char				**world_map;
	unsigned int		width;
	unsigned int		height;
}	t_map;

/*
	All data, like map data, raycasting data, MLX & textures.
*/
typedef struct	s_vars
{
	mlx_t		*mlx;
	t_map		map_data;
	t_textures	textures;
	t_data		data;
}	t_vars;

/*
	CUB3D
*/

int32_t			main(int argc, char *argv[]);

void			raycasting_hook(void *param);

void			draw_hook(void *param);

/*
	FILE CHECK
*/

bool			is_cub_file_valid(char *cub_file, t_vars *vars);

int				read_file(char *cub_file, t_vars *vars);

int				check_map(t_map *map_data);

/*
	UTILS
*/

int				get_next_line(int fd, char **line);

int				loop_through_line(char *map_line, char object);

bool			check_for_holes(char *world_map[], unsigned int height);

void			find_player(t_vars *vars);

/*
	WRAPPED
*/

int				ft_open(char *cub_file);

void			*ft_malloc(size_t size);

/*
	LINKED LIST
*/

void			new_node(t_node **head, char *content);

void			ft_free_list(t_node **head);

size_t			ft_lstlen(t_node *head);


/*
	CHECK_MAP
*/

int				check_player(t_map map_data);

int				check_wall(char *world_map[], unsigned int height);

int				check_unknown(t_map map_data);

/*
	MOVEMENT
*/

void			movement_hook(void *param);

/*
	DRAW
*/

void		draw_cast_east(t_vars *vars, unsigned int x);

void		draw_cast_south(t_vars *vars, unsigned int x);

void		draw_cast_north(t_vars *vars, unsigned int x);

void		draw_cast_west(t_vars *vars, unsigned int x);

void		reset_window(mlx_image_t *screen);

void		draw_floor(t_data data, mlx_image_t *screen, uint32_t colour, int x);

void		draw_ceiling(t_data data, mlx_image_t *screen, uint32_t colour, int x);

uint32_t	create_rgbt(int r, int g, int b, int t);

/*
	RAYCASTING
*/

void	set_delta_dist(t_data *data);

#endif
