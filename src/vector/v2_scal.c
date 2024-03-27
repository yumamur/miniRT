#include <math.h>
#include "../../include/types/vector.h"

float	v2_len(t_v2 a)
{
	return (sqrtf(a.x * a.x + a.y * a.y));
}

float	v2_dot(t_v2 a, t_v2 b)
{
	return (a.x * b.x + a.y * b.y);
}
