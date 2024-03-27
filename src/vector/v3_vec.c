#include "../../include/types/vector.h"
#include <math.h>

extern float	v3_dot(t_v3 a, t_v3 b);

t_v3	v3_norm(t_v3 v) {
    float sq = v3_dot(v, v);

    if (fabs(sq) < 1e-12) {
        return v;
    }
    return v * (1.0 / sqrt(sq));
}

t_v3	v3_proj(t_v3 a, t_v3 b)
{
	return (b * v3_dot(a, b) / v3_dot(b, b));
}

t_v3	v3_cross(t_v3 a, t_v3 b)
{
	t_v3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_v3	v3_reflect(t_v3 a, t_v3 b)
{
	return (a - 2.0f * v3_dot(a, b) * b);
}

t_v3	v3_lerp(t_v3 a, t_v3 b, float t)
{
	return (a + (b - a) * t);
}
