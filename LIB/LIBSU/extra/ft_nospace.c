#include "libft.h"

/*
FT_NOSPACE: 
removes all spaces...
returns the new string without spaces
*/
char		*ft_nospace(char *line)
{
	char	*str;
	int		i;
	int		x;
	int		len;

	i = 0;
	x = 0;
	len = 0;
	len = ft_less_c_len(line, ' ');
	str = (char *)malloc(sizeof(char) * len);
	while (line[i])
	{
		if (line[i] != ' ')
		{
			str[x] = line[i];
			x++;
		}
		i++;
	}
	str[x] = '\0';
	return (str);
}
