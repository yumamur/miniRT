#include <stdlib.h>

void	free_non_null(void *data)
{
	if (data)
		free(data);
}

void	free_and_null(void *data)
{
	if (data)
		free(data);
	data = NULL;
}