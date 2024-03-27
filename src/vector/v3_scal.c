#include <math.h>
#include "./t_vector.h"

float	vf3_dot(t_vf3 a, t_vf3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	vf3_len(t_vf3 a)
{
	return (sqrtf(vf3_dot(a, a)));
}
