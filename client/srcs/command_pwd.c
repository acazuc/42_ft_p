#include "client.h"

void	command_pwd(t_env *env, char **splitted)
{
	char	*path;

	write_long(env, 1);
	path = read_str(env);
	ft_putendl(path);
	ft_putendl("SUCCESS");
	free(path);
	(void)splitted;
}
