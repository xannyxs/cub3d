/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 20:53:06 by swofferh      #+#    #+#                 */
/*   Updated: 2022/07/02 18:08:05 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static void		*free_words(int j, char **words)
{
	while (j != 0)
	{
		j--;
		if (words[j])
			free(words[j]);
	}
	free(words);
	return (NULL);
}

static char		**copy_words(char const *s, char c, char **words)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		words[j] = (char*)ft_malloc(sizeof(char) * ft_wordlen(s, i, c) + 1);
		if (!(words[j]))
			return (free_words(j, words));
		while (s[i] != c && s[i] != '\0')
		{
			words[j][k] = s[i];
			k++;
			i++;
		}
		words[j][k] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}

/*
FT_SPLIT: 
Allocates a string and returns an array of
'words' obtained by splitting it using the character
c as a delimiter. The array must be ended by a
NULL pointer. Returns NULL if the allocation fails.
*/
char			**ft_split(char const *s, char c)
{
	char **words;

	if (!(s))
		return (NULL);
	words = (char**)ft_malloc(sizeof(char*) * (ft_words(s, c) + 1));
	if (!(words))
		return (NULL);
	copy_words(s, c, words);
	return (words);
}
