void	*_errno_location(void)
{
	static int	errno;

	return (&errno);
}

_Bool	errno_isset(void)
{
	return (0);
}
