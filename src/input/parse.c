#include "../libft/libft.h"
#include "../util/error_handler.h"
#include "../vector/t_vector.h"

void	array_free(void *arr);
t_list	*read_file(char *filename);

void	*parse_ambient_light(char **tab);
void	*parse_camera(char **tab);
void	*parse_light(char **tab);
void	*parse_sphere(char **tab);
void	*parse_plane(char **tab);
void	*parse_cylinder(char **tab);
void	*parse_triangle(char **tab);
void	*parse_cone(char **tab);

_Bool	is_float(char *str);
_Bool	is_int(char *str);
float	ft_atof(char *str);

_Bool	parse_vf3(char *str, t_vf3 *addr)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab || !tab[0] || !is_float(tab[0])
		|| !tab[1] || !is_float(tab[1])
		|| !tab[2] || !is_float(tab[2]))
		return (0);
	addr->x = ft_atof(tab[0]);
	addr->y = ft_atof(tab[1]);
	addr->z = ft_atof(tab[2]);
	array_free(tab);
	return (1);
}

_Bool	parse_color(char *str, t_vf3 *addr)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab || !tab[0] || !is_int(tab[0])
		|| !tab[1] || !is_float(tab[1])
		|| !tab[2] || !is_float(tab[2]))
		return (0);
	addr->x = ft_atoi(tab[0]);
	addr->y = ft_atoi(tab[1]);
	addr->z = ft_atoi(tab[2]);
	array_free(tab);
	return (1);
}

static void	*extract_data(void *data)
{
	char	**tab;

	if (!data || errno_isset())
		return (NULL);
	tab = (char **)data;
	if (!ft_strcmp(tab[0], "A"))
		return (parse_ambient_light(tab));
	else if (!ft_strcmp(tab[0], "C"))
		return (parse_camera(tab));
	else if (!ft_strcmp(tab[0], "L"))
		return (parse_light(tab));
	else if (!ft_strcmp(tab[0], "sp"))
		return (parse_sphere(tab));
	else if (!ft_strcmp(tab[0], "pl"))
		return (parse_plane(tab));
	else if (!ft_strcmp(tab[0], "cy"))
		return (parse_cylinder(tab));
	else if (!ft_strcmp(tab[0], "tr"))
		return (parse_triangle(tab));
	else if (!ft_strcmp(tab[0], "cn"))
		return (parse_cone(tab));
	return (NULL);
}

void	parse(char *filename)
{
	t_list	*lines;

	lines = read_file(filename);
	ft_lstmap(lines, extract_data, free);
	ft_lstclear(&lines, array_free);
}
/*
A	0.2											255,255,255

C	-50,0,20		0,0,0		70
L	-40,0,30					0.7				255,255,255

pl	0,0,0			0,1.0,0						255,0,225
sp	0,0,20						20				255,0,0
cy	50.0,0.0,20.6	0,0,1.0		14.2	21.42	10,0,255

	coord			normal		height	width	rgb
*/