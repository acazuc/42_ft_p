#include "client.h"

long	read_long(t_env *env)
{
	long	val;

	if (read(env->sock_fd, &val, sizeof(val)) == -1)
	{
		ft_putendl_fd("client: can't read from socket", 2);
		exit(EXIT_FAILURE);
	}
	return (val);
}

char	*read_str(t_env *env)
{
	char	*str;
	long	len;

	len = read_long(env);
	if (len < 0)
	{
		ft_putendl_fd("client: invalid str length", 2);
		exit(EXIT_FAILURE);
	}
	str = read_mem(env, len);
	return (str);
}

void	*read_mem(t_env *env, long len)
{
	void	*mem;

	if (len < 0)
	{
		ft_putendl_fd("client: invalid memory length", 2);
		exit(EXIT_FAILURE);
	}
	if (!(mem = malloc(len)))
	{
		ft_putendl_fd("client: can't malloc from read_mem", 2);
		exit(EXIT_FAILURE);
	}
	if (read(env->sock_fd, mem, len) == -1)
	{
		ft_putendl_fd("client: can't read from socket", 2);
		exit(EXIT_FAILURE);
	}
	return (mem);
}
