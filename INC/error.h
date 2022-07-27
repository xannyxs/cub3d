/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:58:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/25 18:03:08 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define SUCCES 0
# define ERROR 1

# define NONVALID_FILE "-- Non valid extension. Need a .cub file! --"
# define ARGC_ERROR "-- I only need a .cub file --"
# define EMPTY_FILE "-- File is empty --"
# define LAST_LINE_EMPTY "-- Empty line --"

# define PATH_ERROR "-- Something went wrong processing png path --"
# define WRONG_NUMBER "-- Colors input needs to be in [0,255] range --"
# define RBG_ERROR "-- I need three colour inputs --"

# define GNL_ERROR "-- Something went wrong while reading .cub file --"
# define NO_PATH "-- File input is invalid, fix the path/colour jonguh --"

# define MISSING_WALL "-- Missing wall surrounding the map --"
# define MISSING_PLAYER "-- Missing player --"
# define TOO_MANY_PLAYERS "-- Too many players in the map --"
# define UNKNOWN_CHAR "-- Unknown character in map --"
# define NONVALID_MONITOR "-- Your monitor size is too small --"

/*
	ERROR
*/

void	non_fatal_error(char *msg);

void	fatal_perror(char *msg);

#endif
