#include <math.h>
#include "../../include/types/t_vector.h"

float	v3_dot(t_v3 a, t_v3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float	v3_len(t_v3 a)
{
	return (sqrtf(v3_dot(a, a)));
}
