#include "server.h"

void run(t_env *env)
{
	socklen_t socklen;
	pid_t pid;
	int fd;

	socklen = sizeof(env->sockaddr);
	while (1)
	{
		if ((fd = accept(env->sock_fd, (struct sockaddr*)&env->sockaddr, &socklen)) == -1)
			ft_exit("server: error while listening", EXIT_FAILURE);
		pid = fork();
		if (pid == 0)
		{
			run_client(env, fd);
			exit(EXIT_SUCCESS);
		}
		else if (pid == -1)
			ft_exit("server: can't fork", EXIT_FAILURE);
		close(fd);
	}
}
