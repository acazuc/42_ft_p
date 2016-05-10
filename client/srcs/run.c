#include "client.h"

void	run(t_env *env)
{
	char	*command;
	while (1)
	{
		ft_putstr("ft_p_client> ");
		command = get_next_command();
		run_command(env, command);
		free(command);
	}
}
