/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 21:09:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void execute_ls(t_client *client, char **av)
{
	if (dup2(client->sock_fd, 1) == -1)
		ft_exit("dup2 failed", EXIT_FAILURE);
	if (dup2(client->sock_fd, 2) == -1)
		ft_exit("dup2 failed", EXIT_FAILURE);
	execv("/bin/ls", av);
	exit(EXIT_FAILURE);
}

static char	**read_args(t_client *client)
{
	char	**av;
	long	ac;
	long	i;

	ac = read_long(client);
	if (!(av = malloc(sizeof(*av) * (ac + 2))))
		ft_exit("malloc failed", EXIT_FAILURE);
	av[0] = "/bin/ls";
	av[ac + 1] = NULL;
	i = 0;
	while (i < ac)
		av[++i] = read_str(client);
	ls_replace_args(client, av);
	return (av);
}

void	command_ls(t_client *client)
{
	pid_t	pid;
	int		status;
	char	**av;
	int		i;

	av = read_args(client);
	if ((pid = fork()) == -1)
		ft_exit("fork failed", EXIT_FAILURE);
	if (pid == 0)
		execute_ls(client, av);
	else
		wait4(pid, &status, 0, NULL);
	write_byte(client, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		ft_exit("ls failure", EXIT_FAILURE);
	i = 1;
	while (av[i])
		free(av[i++]);
	free(av);
}
