#ifndef T_LIGHT_H
# define T_LIGHT_H

# include "./t_vector.h"

enum e_light_type
{
	POINT,
	AMBIENT,
};

typedef struct s_light
{
	enum e_light_type	type;
	void				*data;
}	t_light;

typedef struct s_ambient_light
{
	t_v3	color;
}	t_ambient_light;

typedef struct s_point_light
{
	t_v3	position;
	t_v3	color;
	float	intensity;
}	t_point_light;

typedef struct s_spot_light
{
	t_v3	position;
	t_v3	color;
	t_v3	direction;
	float	intensity;
}	t_spot_light;

#endif
