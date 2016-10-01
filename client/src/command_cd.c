/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 11:42:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	command_cd(t_env *env, char **splitted)
{
	long result;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a folder to go in");
		return ;
	}
	write_long(env, COMMAND_CD);
	write_str(env, splitted[1]);
	result = read_long(env);
	if (result == -1)
		ft_putendl("ERROR: this folder doesn't exists");
	else if (result == -2)
		ft_putendl("ERROR: you don't have the permissions");
	else if (result == -3)
		ft_putendl("ERROR: unknown error");
	else if (result == -4)
		ft_putendl("ERROR: not a directory");
	else if (result == 0)
		ft_putendl("SUCCESS");
}
