#include "client.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 3)
		ft_exit("client: invalid arguments\nclient <host> <port>", EXIT_FAILURE);
	parse_arguments(&env, av);
	resolve_host(&env);
	server_connect(&env);
	run(&env);
}
