/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libsu.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 17:10:52 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/25 15:10:32 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSU_H
# define LIBSU_H

# include "libft.h"

/*					Extra functions (outside libft)
*/
long				ft_atol(const char *str);
int					ft_open(char *cub_file);
int					ft_isspace(char c);
int					ft_isnull(char c);
int					ft_isupper(int n);
int					ft_islower(int n);

/*  My printing functions */

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);

void				ft_putoctal(unsigned long n);
void				ft_puthexa(unsigned long n);
void				ft_putbase(long long nbr, int base);

int					ft_less_c_len(char *line, char c);
int					ft_putlen(char c, int len);

/*  My STR functions */

char				*ft_strrev(char *s);
char				*ft_strndup(char *s, int start);

/*   My LEN functions */

int					ft_numlen(int n);
size_t				ft_lenbase(long long nbr, int base);
int					ft_wordlen(char const *str, int i, char space);
int					ft_strclen(char *str, char c);
int					ft_textsize(const char *str);

/*  My WORDS functions */

int					ft_words(char const *str, char space);
char				*ft_nospace(char *line);

/* extra Array functions */

char				*ft_strjoin_free(char *str1, char *str2);
void				ft_free_array(char **str);
void				ft_print_array(char *array[]);

/* Operators */

void				*ft_malloc(size_t size);

#endif
