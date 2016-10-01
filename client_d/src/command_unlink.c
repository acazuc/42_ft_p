/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unlink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:22:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 12:58:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	put_error(long error)
{
	if (error == -1)
		ft_putendl("ERROR: invalid directory");
	else if (error == -2)
		ft_putendl("ERROR: file doesn't exists");
	else if (error == -3)
		ft_putendl("ERROR: file is a directory, use rmdir");
	else if (error == -4)
		ft_putendl("ERROR: permission denied");
	else if (error == -5)
		ft_putendl("ERROR: unknown error");
}

void		command_unlink(t_env *env, char **splitted)
{
	long	result;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a file name");
		return ;
	}
	write_long(env, COMMAND_TOUCH);
	write_str(env, splitted[1]);
	if ((result = read_long(env)) == 1)
		ft_putendl("SUCCESS");
	else
		put_error(result);
}
