/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_connect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 16:20:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	server_connect(t_env *env)
{
	int		opt_val;

	opt_val = 1;
	if ((env->sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
		ft_exit("client: can't create socket", EXIT_FAILURE);
	if (connect(env->sock_fd, (struct sockaddr*)env->sockaddr
				, sizeof(*env->sockaddr)) == -1)
		ft_exit("client: can't connect to host", EXIT_FAILURE);
	if (SO_NOSIGPIPE && setsockopt(env->sock_fd, SOL_SOCKET, SO_NOSIGPIPE
				, &opt_val, sizeof(opt_val)) == -1)
		ft_exit("client: can't set NO_SIGPIPE", EXIT_FAILURE);
}
