/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_start_slash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:32:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 21:38:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*replace_start_slash(t_client *client, char *str)
{
	char	*ret;

	if (str[0] != '/')
		return (str);
	if (!(ret = ft_strjoin_free2(client->origin_path, str)))
		ft_exit("ft_strjoin failed", EXIT_FAILURE);
	return (ret);
}
