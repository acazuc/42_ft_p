#include "server.h"

long	read_long(t_client *client)
{
	long	val;

	if (read(client->sock_fd, &val, sizeof(val)) <= 0)
	{
		ft_putendl_fd("client: can't read from socket", 2);
		exit(EXIT_FAILURE);
	}
	return (val);
}

char	*read_str(t_client *client)
{
	char	*str;
	long	len;

	len = read_long(client);
	if (len < 0)
	{
		ft_putendl_fd("client: invalid str length", 2);
		exit(EXIT_FAILURE);
	}
	str = read_mem(client, len);
	return (str);
}

void	*read_mem(t_client *client, long len)
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
	if (read(client->sock_fd, mem, len) <= 0)
	{
		ft_putendl_fd("client: can't read from socket", 2);
		exit(EXIT_FAILURE);
	}
	return (mem);
}
