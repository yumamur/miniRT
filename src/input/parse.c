#include "../../libft/libft.h"
#include <fcntl.h>

static t_list	*read_file(char *filename)
{
	int		fd;
	char	*line;
	t_list	*lst;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line != '\0' && ft_strlen(line) >= 10)
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
			free(line);
		}
	}
	return (lst);
}

static void	arr_free(void *data)
{
	int		i;
	char	**arr;

	i = 0;
	arr  = data;
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
	int		j;

	tab = ft_split(line, ' ');
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (*tab[i] != '\0')
		{
			tab[j] = tab[i];
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

void	parse(char *filename)
{
	t_list	*lines;

	lines = read_file(filename);
	ft_lstmap(lines, str_to_wordtab, arr_free);
}