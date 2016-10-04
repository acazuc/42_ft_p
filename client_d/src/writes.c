/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 17:16:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	write_long(t_env *env, long val)
{
	if (write(env->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("client: can't write long value", EXIT_FAILURE);
}

void	write_str(t_env *env, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write_long(env, len + 1);
	write_mem(env, str, len + 1);
}

void	write_mem(t_env *env, void *data, size_t len)
{
	if (write(env->sock_fd, data, len) != (ssize_t)len)
		ft_exit("client: can't write mem value", EXIT_FAILURE);
}
