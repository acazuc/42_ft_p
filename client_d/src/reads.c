/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/30 23:17:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

long	read_long(t_env *env)
{
	long	val;

	if (read(env->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("client: can't read from socket", EXIT_FAILURE);
	return (val);
}

char	*read_str(t_env *env)
{
	char	*str;
	long	len;

	len = read_long(env);
	if (len <= 0)
		ft_exit("client: invalid str length", EXIT_FAILURE);
	str = read_mem(env, len);
	return (str);
}

void	*read_mem(t_env *env, long len)
{
	void	*mem;

	if (len <= 0)
		ft_exit("client: invalid memory length", EXIT_FAILURE);
	if (!(mem = malloc(len)))
		ft_exit("client: can't malloc from read_mem", EXIT_FAILURE);
	if (read(env->sock_fd, mem, len) != len)
		ft_exit("client: can't read from socket", EXIT_FAILURE);
	return (mem);
}
