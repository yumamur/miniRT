#include <math.h>
#include "../../include/types/t_vector.h"

extern float	v2_dot(t_v2 a, t_v2 b);

t_v2	v2_norm(t_v2 v)
{
	float	sq;

	sq = v2_dot(v, v);
	if (fabs(sq) < 1e-12)
	{
		return (v);
	}
	return (v * (1.0 / sqrt(sq)));
}
