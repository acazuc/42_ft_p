#include "client.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 3)
	{
		ft_putendl_fd("client: invalid arguments\nclient <host> <port>", 2);
		exit(EXIT_FAILURE);
	}
	parse_arguments(&env, av);
	resolve_host(&env);
	server_connect(&env);
	run(&env);
}
