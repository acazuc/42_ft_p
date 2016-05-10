#include "client.h"

void	command_ls(t_env *env, char **splitted)
{
	char *tmp;
	long	number;

	write_long(env, 2);
	number = read_long(env);
	if (number == -1)
	{
		ft_putendl("ERROR: can't opendir");
		return;
	}
	tmp = read_str(env);
	while (ft_strlen(tmp))
	{
		ft_putendl(tmp);
		free(tmp);
		tmp = read_str(env);
	}
	ft_putendl("SUCCESS");
	(void)splitted;
}
