#include "client.h"

void	command_quit(t_env *env, char **splitted)
{
	write_long(env, 4);
	exit(EXIT_SUCCESS);
	(void)env;
	(void)splitted;
}
