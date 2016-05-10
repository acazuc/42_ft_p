#include "server.h"

void run_client(t_env *env, int fd)
{
	t_client client;
	long packet_id;

	ft_putendl_fd("new client connected", 2);
	if (!(client.path = malloc(sizeof(*client.path) * 2)))
	{
		ft_putendl_fd("server: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	client.path[0] = '.';
	client.path[1] = '\0';
	client.sock_fd = fd;
	while (1)
	{
		if (read(client.sock_fd, &packet_id, sizeof(packet_id)) < 0)
		{
			ft_putendl("client shutdown");
			exit(EXIT_SUCCESS);
		}
		if (packet_id == 1)
			command_pwd(&client);
		else if (packet_id == 2)
			command_ls(&client);
		else if (packet_id == 3)
			command_cd(&client);
		else if (packet_id == 4)
		{
			ft_putendl("client shutdown");
			exit(EXIT_FAILURE);
		}
		else
		{
			ft_putendl("unknown packet");
			exit(EXIT_FAILURE);
		}
	}
	(void)env;
}
