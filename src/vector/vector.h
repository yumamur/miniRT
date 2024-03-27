#ifndef VECTOR_H
# define VECTOR_H

# include "./t_vector.h"

float	v2_len(t_v2 a);
float	v2_dot(t_v2 a, t_v2 b);
t_v2	v2_norm(t_v2 a);

float	vf3_len(t_vf3 a);
float	vf3_dot(t_vf3 a, t_vf3 b);
t_vf3	vf3_norm(t_vf3 a);
t_vf3	vf3_proj(t_vf3 a, t_vf3 b);
t_vf3	vf3_cross(t_vf3 a, t_vf3 b);
t_vf3	vf3_reflect(t_vf3 a, t_vf3 b);
t_vf3	vf3_lerp(t_vf3 a, t_vf3 b, float t);

#endif