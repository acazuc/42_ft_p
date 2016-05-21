/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:47:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
