#include "server.h"

static int	valid_port(char *port)
{
	if (!ft_strisdigit(port))
	{
		return (0);
	}
	while (port[0] == '0')
		port++;
	if (ft_strlen(port) > 5 || ft_strlen(port) < 1)
		return (0);
	if (ft_atoi(port) > USHRT_MAX)
		return (0);
	return (1);
}

void parse_parameters(t_env *env, char **av)
{
	if (!valid_port(av[1]))
	{
		ft_putendl_fd("server: invalid port", 2);
		exit(EXIT_FAILURE);
	}
	env->port = ft_atoi(av[1]);
}
