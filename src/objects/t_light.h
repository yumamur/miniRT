#ifndef T_LIGHT_H
# define T_LIGHT_H

# include "../vector/t_vector.h"

enum e_light_type
{
	POINT,
	AMBIENT,
	SPOT
};

typedef struct s_light
{
	enum e_light_type	type;
	t_vf3				position;
	t_vf3				color;
	t_vf3				direction;
	float				ratio;
}	t_light;

#endif
