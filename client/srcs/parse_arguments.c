#include "client.h"

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

void	parse_arguments(t_env *env, char **av)
{
	env->host = av[1];
	if (!valid_port(av[2]))
		ft_exit("client: invalid port number", EXIT_FAILURE);
	env->port = (unsigned short)ft_atoi(av[2]);
}
