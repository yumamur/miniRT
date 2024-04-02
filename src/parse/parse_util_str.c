#include "libft.h"

void	*str_to_wordtab(void *line)
{
	char	**tab;
	char	*tmp;
	int		i;

	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i])
	{
		tmp = ft_strtrim(tab[i], "\t\n\v\f\r");
		free(tab[i]);
		tab[i] = tmp;
		i++;
	}
	return (tab);
}