/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:22 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:45:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	command_quit(t_env *env, char **splitted)
{
	write_long(env, 4);
	exit(EXIT_SUCCESS);
	(void)env;
	(void)splitted;
}
