#include "server.h"

void command_pwd(t_client *client)
{
	char *str;

	if (!(str = ft_strjoin(client->path, "/")))
	{
		ft_putendl_fd("server: can't join", 2);
		exit(EXIT_FAILURE);
	}
	write_str(client, str);
}
