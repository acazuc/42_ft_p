/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:33 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 16:02:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	run(t_env *env)
{
	socklen_t	socklen;
	pid_t		pid;
	int			fd;

	socklen = sizeof(env->sockaddr);
	while (1)
	{
		if ((fd = accept(env->sock_fd
						, (struct sockaddr*)&env->sockaddr, &socklen)) == -1)
			ft_exit("server: error while listening", EXIT_FAILURE);
		pid = fork();
		if (pid == 0)
		{
			run_client(fd);
			exit(EXIT_SUCCESS);
		}
		else if (pid == -1)
			ft_exit("server: can't fork", EXIT_FAILURE);
		close(fd);
	}
}
