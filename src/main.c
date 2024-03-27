#include "../include/main.h"

int	main(int argc, char *argv[])
{
	void	*scene;

	validate(argc, argv);
	scene = parse(argv[1]);
	if (!scene)
	{
		handle_error(1);
	}
	render(scene);
	return (0);
}
