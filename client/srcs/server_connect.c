#include "client.h"

void	server_connect(t_env *env)
{
	if ((env->sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
		ft_putendl_fd("client: can't create socket", 2);
		exit(EXIT_FAILURE);
	}
	if (connect(env->sock_fd, (struct sockaddr*)env->sockaddr, sizeof(*env->sockaddr)) == -1)
	{
		ft_putendl_fd("client: can't connect to host", 2);
		exit(EXIT_FAILURE);
	}
}
