_Bool	is_float(char *str)
{
	if (*str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (!*str);
}

float	ft_atof(char *str)
{
	float	res;
	float	dec;
	int		sign;

	res = 0;
	dec = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		dec = dec * 10 + *str++ - '0';
		res *= 10;
	}
	return ((res + dec) * sign);
}
