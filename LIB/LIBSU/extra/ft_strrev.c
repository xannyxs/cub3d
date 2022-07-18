/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 19:39:31 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/06 17:29:47 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	rev;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		rev = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = rev;
		i++;
	}
	return (s);
}
