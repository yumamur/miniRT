#include <stdlib.h>
#include <fcntl.h>
#include "../../libft/libft.h"

static _Bool	validate_extension(char *filename, char *ext)
{
	char	*file_ext;

	file_ext = ft_strrchr(filename, '.');
	if (file_ext && ft_strcmp(file_ext, ext) == 0)
	{
		return 1;
	}
	return 0;
}

static _Bool	is_file_available(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return 1;
	}
	return 0;
}

static _Bool	is_valid(char *filename)
{
	if (filename && *filename  != '\0' && ft_strlen(filename) > 4
		&& validate_extension(filename, ".rt")
		&& is_file_available(filename))
	{
		return 1;
	}
	return 0;
}

void	validate(int argc, char *argv[])
{
	if (argc != 2 || !is_valid(argv[1]))
	{
		exit(1);
	}
}