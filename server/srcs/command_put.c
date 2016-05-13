#include "server.h"

static char *get_file_name(char *file)
{
	char **splitted;
	char *res;
	int i;

	if (!(splitted = ft_strsplit(file, '/')))
	{
		ft_putendl_fd("server: can't split file name", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (splitted[i])
	{
		if (splitted[i + 1])
			free(splitted[i]);
		else
		{
			res = splitted[i];
			free(splitted);
			free(file);
			return (res);
		}
		i++;
	}
	return (NULL);
}

static void read_file(t_client *client, int fd)
{
	long tmp;
	char *data;

	while ((tmp = read_long(client)) >= 0)
	{
		data = read_mem(client, tmp);
		tmp = write(fd, data, tmp);
	}
}

void command_put(t_client *client)
{
	char *file;
	int fd;

	file = read_str(client);
	file = get_file_name(file);
	if (!(file = ft_strjoin_free2("./", file)))
	{
		ft_putendl_fd("server: can't join file name", 2);
		exit(EXIT_FAILURE);
	}
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		if (errno == EACCES)
			write_long(client, -1);
		else
			write_long(client, -2);
		return;
	}
	write_long(client, 1);
	read_file(client, fd);
	close(fd);
	(void)client;
}
