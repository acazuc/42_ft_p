#include "server.h"

void command_cd(t_client *client)
{
	char *current;
	char *gpath;
	char *new;

	gpath = read_str(client);
	if (!(current = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(current, PATH_MAX + 1);
	if (!getcwd(current, PATH_MAX))
		ft_putendl_fd("server: can't getcwd", EXIT_FAILURE);
	if (chdir(gpath) == -1)
	{
		if (errno == EACCES)
			write_long(client, -2);
		else if (errno == ENOENT)
			write_long(client, -1);
		else if (errno == ENOTDIR)
			write_long(client, -4);
		else
			write_long(client, -3);
		free(gpath);
		free(current);
		return;
	}
	if (!(new = malloc(PATH_MAX + 1)))
		ft_putendl_fd("server: can't malloc", EXIT_FAILURE);
	ft_bzero(new, PATH_MAX + 1);
	if (!getcwd(new, PATH_MAX))
		ft_putendl_fd("server: can't getcwd", EXIT_FAILURE);
	if (ft_strstr(new, client->origin_path) != new)
	{
		free(gpath);
		free(new);
		free(current);
		int lol = chdir(current);
		lol = -2;
		write_long(client, lol);
		return ;
	}
	write_long(client, 0);
}
