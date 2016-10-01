/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 12:07:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	splitted_free(char **splitted)
{
	int		i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void		run_command(t_env *env, char *command)
{
	char	**splitted;

	if (!(splitted = ft_strsplit(command, ' ')))
		ft_exit("client: can't split command", EXIT_FAILURE);
	if (splitted[0])
	{
		if (!ft_strcmp(splitted[0], "ls"))
			command_ls(env, splitted);
		else if (!ft_strcmp(splitted[0], "cd"))
			command_cd(env, splitted);
		else if (!ft_strcmp(splitted[0], "get"))
			command_get(env, splitted);
		else if (!ft_strcmp(splitted[0], "put"))
			command_put(env, splitted);
		else if (!ft_strcmp(splitted[0], "pwd"))
			command_pwd(env, splitted);
		else if (!ft_strcmp(splitted[0], "quit"))
			command_quit(env, splitted);
		else if (!ft_strcmp(splitted[0], "touch"))
			command_touch(env, splitted);
		else
			ft_putendl("unknown command");
	}
	splitted_free(splitted);
}
