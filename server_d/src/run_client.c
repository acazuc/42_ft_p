/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 16:20:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		set_nosigpipe(int fd)
{
	int		opt_val;

	opt_val = 1;
	if (!SO_NOSIGPIPE)
		return ;
	if (setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &opt_val
				, sizeof(opt_val)) == -1)
		ft_exit("server: can't set NO_SIGPIPE", EXIT_FAILURE);
}

static void		set_current_path(t_client *client)
{
	if (!(client->origin_path = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	if (!getcwd(client->origin_path, PATH_MAX))
		ft_exit("server: can't malloc", EXIT_FAILURE);
}

static int		do_action(long packet_id, t_client *client)
{
	if (packet_id == COMMAND_PWD)
		command_pwd(client);
	else if (packet_id == COMMAND_LS)
		command_ls(client);
	else if (packet_id == COMMAND_CD)
		command_cd(client);
	else if (packet_id == COMMAND_QUIT)
		ft_exit("server: client shutdown", EXIT_FAILURE);
	else if (packet_id == COMMAND_PUT)
		command_put(client);
	else if (packet_id == COMMAND_GET)
		command_get(client);
	else if (packet_id == COMMAND_TOUCH)
		command_touch(client);
	else if (packet_id == COMMAND_UNLINK)
		command_unlink(client);
	else
		return (0);
	return (1);
}

void			run_client(int fd)
{
	t_client	client;
	long		packet_id;

	client.sock_fd = fd;
	set_nosigpipe(client.sock_fd);
	set_current_path(&client);
	while (1)
	{
		if (read(client.sock_fd, &packet_id, sizeof(packet_id)) <= 0)
			ft_exit("server: client shutdown", EXIT_SUCCESS);
		if (!do_action(packet_id, &client))
			ft_exit("unknown packet", EXIT_FAILURE);
	}
}
