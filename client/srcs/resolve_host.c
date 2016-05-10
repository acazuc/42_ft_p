#include "client.h"

void	resolve_host(t_env *env)
{
	struct hostent	*hostent;

	if (!(env->sockaddr = malloc(sizeof(*env->sockaddr))))
	{
		ft_putendl_fd("client: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(env->sockaddr, sizeof(*env->sockaddr));
	if (!(hostent = gethostbyname(env->host)))
	{
		ft_putendl_fd("client: can't resolve host", 2);
		exit(EXIT_FAILURE);
	}
	if (hostent->h_addrtype != AF_INET)
	{
		ft_putendl_fd("client: can't resolve host to ipv4 address", 2);
		exit(EXIT_FAILURE);
	}
	env->sockaddr->sin_family = AF_INET;
	env->sockaddr->sin_port = htons(env->port);
	env->sockaddr->sin_addr = *((struct in_addr*)hostent->h_addr);
}
