/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arg_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:49:05 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 21:49:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ls_replace_arg_2(t_client *client, char **arg, int is_dir, char *name)
{
	free(*arg);
	if (!(*arg = ft_strdup(client->origin_path)))
		ft_exit("ft_strdup failed", EXIT_FAILURE);
	if (!is_dir)
	{
		if (!(*arg = ft_strjoin_free1(*arg, "/")))
			ft_exit("ft_strjoin failed", EXIT_FAILURE);
		if (!(*arg = ft_strjoin_free1(*arg, name)))
			ft_exit("ft_strjoin failed", EXIT_FAILURE);
	}
}
