#include "server.h"

static void set_current_path(t_client *client)
{
	if (!(client->origin_path = malloc(PATH_MAX + 1)))
	{
		ft_putendl_fd("server: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	if (!getcwd(client->origin_path, PATH_MAX))
	{
		ft_putendl_fd("server: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
}

void run_client(t_env *env, int fd)
{
	t_client client;
	long packet_id;

	ft_putendl_fd("server: new client connected", 2);
	client.sock_fd = fd;
	set_current_path(&client);
	while (1)
	{
		if (read(client.sock_fd, &packet_id, sizeof(packet_id)) <= 0)
		{
			ft_putendl_fd("server: client shutdown", 2);
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
			ft_putendl_fd("server: client shutdown", 2);
			exit(EXIT_FAILURE);
		}
		else if (packet_id == 5)
			command_put(&client);
		else if (packet_id == 6)
			command_get(&client);
		else
		{
			ft_putendl_fd("unknown packet", 2);
			exit(EXIT_FAILURE);
		}
	}
	(void)env;
}
