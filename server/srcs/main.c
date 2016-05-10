#include "server.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
	{
		ft_putendl_fd("server: invalid arguments\nserver <port>", 2);
		exit(EXIT_FAILURE);
	}
	parse_parameters(&env, av);
	build_host(&env);
	run(&env);
	return (EXIT_SUCCESS);
}
