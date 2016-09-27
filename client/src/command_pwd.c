/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:45:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
