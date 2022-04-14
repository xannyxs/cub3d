/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/14 16:19:47 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_vars {
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_vars;

/*
	CUB3D
*/

int	main(void);

#endif