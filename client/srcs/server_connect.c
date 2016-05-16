#include "client.h"

void	server_connect(t_env *env)
{
	if ((env->sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		ft_exit("client: can't create socket", EXIT_FAILURE);
	if (connect(env->sock_fd, (struct sockaddr*)env->sockaddr, sizeof(*env->sockaddr)) == -1)
		ft_exit("client: can't connect to host", EXIT_FAILURE);
}
