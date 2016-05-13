#include "server.h"

static void put_file(t_client *client, int fd)
{
	ssize_t readed;
	char *buff;

	if (!(buff = malloc(sizeof(*buff) * 500)))
	{
		ft_putendl_fd("client: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	while ((readed = read(fd, buff, 500)) > 0)
	{
		write_long(client, readed);
		write_mem(client, buff, readed);
	}
	if (readed == -1)
		write_long(client, -2);
	else
		write_long(env, -1);
	free(buff);
}

void command_get(t_client *client)
{
	(void)client;
}
