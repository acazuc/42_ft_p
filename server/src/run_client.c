/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 16:02:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		set_current_path(t_client *client)
{
	if (!(client->origin_path = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	if (!getcwd(client->origin_path, PATH_MAX))
		ft_exit("server: can't malloc", EXIT_FAILURE);
}

void			run_client(int fd)
{
	t_client	client;
	long		packet_id;

	ft_putendl_fd("server: new client connected", 2);
	client.sock_fd = fd;
	set_current_path(&client);
	while (1)
	{
		if (read(client.sock_fd, &packet_id, sizeof(packet_id)) <= 0)
			ft_exit("server: client shutdown", EXIT_SUCCESS);
		if (packet_id == 1)
			command_pwd(&client);
		else if (packet_id == 2)
			command_ls(&client);
		else if (packet_id == 3)
			command_cd(&client);
		else if (packet_id == 4)
			ft_exit("server: client shutdown", EXIT_FAILURE);
		else if (packet_id == 5)
			command_put(&client);
		else if (packet_id == 6)
			command_get(&client);
		else
			ft_exit("unknown packet", EXIT_FAILURE);
	}
}
