/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_mkdir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 13:58:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 14:07:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	put_error(long error)
{
	if (error == -1)
		ft_putendl("ERROR: invalid directory");
	else if (error == -2)
		ft_putendl("ERROR: can't create directory");
	else if (error == -3)
		ft_putendl("ERROR: directory already exists");
}

void		command_mkdir(t_env *env, char **splitted)
{
	long	result;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a file name");
		return ;
	}
	write_long(env, COMMAND_MKDIR);
	write_str(env, splitted[1]);
	if ((result = read_long(env)) == 1)
		ft_putendl("SUCCESS");
	else
		put_error(result);
}
