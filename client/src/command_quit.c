/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 11:43:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	command_quit(t_env *env, char **splitted)
{
	write_long(env, COMMAND_QUIT);
	exit(EXIT_SUCCESS);
	(void)env;
	(void)splitted;
}
