/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_host.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:38 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:45:39 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	resolve_host(t_env *env)
{
	struct hostent	*hostent;

	if (!(env->sockaddr = malloc(sizeof(*env->sockaddr))))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	ft_bzero(env->sockaddr, sizeof(*env->sockaddr));
	if (!(hostent = gethostbyname(env->host)))
		ft_exit("client: can't resolve host", EXIT_FAILURE);
	if (hostent->h_addrtype != AF_INET)
		ft_exit("client: can't resolve host to ipv4 address", EXIT_FAILURE);
	env->sockaddr->sin_family = AF_INET;
	env->sockaddr->sin_port = htons(env->port);
	env->sockaddr->sin_addr = *((struct in_addr*)hostent->h_addr);
}
