#include "client.h"

void	write_long(t_env *env, long val)
{
	if (write(env->sock_fd, &val, sizeof(val)) == -1)
		ft_exit("client: can't write long value", EXIT_FAILURE);
}

void	write_str(t_env *env, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write_long(env, len + 1);
	write_mem(env, str, len + 1);
}

void	write_mem(t_env *env, void *data, size_t len)
{
	if (write(env->sock_fd, data, len) == -1)
		ft_exit("client: can't write mem value", EXIT_FAILURE);
}
