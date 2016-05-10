#include "server.h"

void build_host(t_env *env)
{

	if ((env->sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
	{
		ft_putendl_fd("client: can't create socket", 2);
		exit(EXIT_FAILURE);
	}
	env->sockaddr.sin_family = AF_INET;
	env->sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	env->sockaddr.sin_port = htons(env->port);
	if (bind(env->sock_fd, (struct sockaddr*)&env->sockaddr, sizeof(env->sockaddr)) == -1)
	{
		ft_putendl_fd("server: can't bind socket (port may already be used)", 2);
		exit(EXIT_FAILURE);
	}
	if (listen(env->sock_fd, 500) == -1)
	{
		ft_putendl_fd("server: can't listen", 2);
		exit(EXIT_FAILURE);
	}
}
