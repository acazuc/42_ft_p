#include "server.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		ft_exit("server: invalid arguments\nserver <port>", EXIT_FAILURE);
	parse_parameters(&env, av);
	build_host(&env);
	run(&env);
	return (EXIT_SUCCESS);
}
