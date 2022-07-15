/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 18:25:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/15 13:20:29 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h" /* GNL ERROR */
#include "libft.h"

#include <fcntl.h> /* open */
#include <unistd.h> /* close */
#include <stdlib.h> /* malloc */

static void	alloc_list_to_array(t_map *map_data, t_node **file_content)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *file_content;
	map_data->world_map = ft_malloc(ft_lstlen(*file_content) * sizeof(char *));
	while (temp->next != NULL)
	{
		map_data->world_map[i] = temp->content;
		i++;
		temp = temp->next;
	}
	map_data->world_map[i] = NULL;
	ft_free_list(file_content);
}

static int	get_lines(char *cub_file, t_node **file_content)
{
	int		fd;
	int		err;
	char	*line;

	err = 1;
	fd = ft_open(cub_file);
	while (err > 0)
	{
		err = get_next_line(fd, &line);
		if (err == -1)
		{
			close(fd);
			non_fatal_error(GNL_ERROR);
			return (ERROR);
		}
		new_node(file_content, line);
	}
	new_node(file_content, line);
	close(fd);
	return (SUCCES);
}

/*
	Reads file of user by using "get_next_line"
	and puts it in a linked list.
	It will convert the linked list to an 2D Array.
*/
int	read_file(char *cub_file, t_vars *vars)
{
	t_node	*file_content;

	file_content = NULL;
	if (get_lines(cub_file, &file_content))
		return (ERROR);
	alloc_list_to_array(&vars->map_data, &file_content);
	return (SUCCES);
}
