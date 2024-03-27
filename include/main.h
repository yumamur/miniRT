#ifndef MAIN_H
# define MAIN_H

void	handle_error(int error_code);

_Bool	is_valid(char *filename);
void	validate(int argc, char *argv[]);
void	*parse(char *filename);
void	render(void *scene);

#endif