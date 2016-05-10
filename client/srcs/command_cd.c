#include "client.h"

void	command_cd(t_env *env, char **splitted)
{
	long result;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a folder to go in");
		return ;
	}
	write_long(env, 3);
	write_str(env, splitted[1]);
	result = read_long(env);
	if (result == -1)
	{
		ft_putendl("ERROR: this folder doesn't exists");
		return ;
	}
	else if (result == -2)
	{
		ft_putendl("ERROR: you don't have the permissions");
		return ;
	}
	else if (result == 0)
	{
		ft_putendl("SUCCESS");
	}
}
