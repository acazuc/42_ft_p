#include "client.h"

static void put_file(t_env *env, int fd)
{
	ssize_t readed;
	char *buff;

	if (!(buff = malloc(sizeof(*buff) * 500)))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	while ((readed = read(fd, buff, 500)) > 0)
	{
		write_long(env, readed);
		write_mem(env, buff, readed);
	}
	if (readed == -1)
		ft_putendl("ERROR: can't read file");
	write_long(env, -1);
	free(buff);
}

void	command_put(t_env *env, char **splitted)
{
	int result;
	int fd;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a file name");
		return;
	}
	if ((fd = open(splitted[1], O_RDONLY)) == -1)
	{
		ft_putendl("ERROR: can't open file");
		return;
	}
	write_long(env, 5);
	write_str(env, splitted[1]);
	if ((result = read_long(env)) == 1)
		put_file(env, fd);
	else if (result == -1)
		ft_putendl("ERROR: you don't have permissions");
	else if (result == -2)
		ft_putendl("ERROR: can't create file");
	else
		ft_putendl("ERROR: unknown error");
	close(fd);
}
