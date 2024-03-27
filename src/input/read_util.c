#include <fcntl.h>
#include "../libft/libft.h"

void	array_free(void *data)
{
	void	**arr;
	int		i;

	i = 0;
	arr = (void **)data;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	*str_to_wordtab(void *line)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i])
	{
		ft_strtrim(tab[i], "\t\n\v\f\r");
		i++;
	}
	return (tab);
}

t_list	*read_file(char *filename)
{
	int		fd;
	char	*line;
	t_list	*lst;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line != '\0' && ft_strlen(line) >= 10)
		{
			ft_lstadd_back(&lst, ft_lstnew(str_to_wordtab(line)));
			free(line);
		}
	}
	return (lst);
}
