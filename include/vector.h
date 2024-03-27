#ifndef VECTOR_H
# define VECTOR_H

# include "types/vector.h"

float	v2_len(t_v2 a);
float	v2_dot(t_v2 a, t_v2 b);
t_v2	v2_norm(t_v2 a);

float	v3_len(t_v3 a);
float	v3_dot(t_v3 a, t_v3 b);
t_v3	v3_norm(t_v3 a);
t_v3	v3_proj(t_v3 a, t_v3 b);
t_v3	v3_cross(t_v3 a, t_v3 b);
t_v3	v3_reflect(t_v3 a, t_v3 b);
t_v3	v3_lerp(t_v3 a, t_v3 b, float t);

#endif