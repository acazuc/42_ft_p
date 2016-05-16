#include "server.h"

void command_pwd(t_client *client)
{
	char *current;

	if (!(current = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(current, PATH_MAX + 1);
	if (!getcwd(current, PATH_MAX))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	current = current + ft_strlen(client->origin_path);
	current[ft_strlen(current)] = '/';
	write_str(client, current);
	free(current - ft_strlen(client->origin_path));
}
