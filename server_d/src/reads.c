/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 20:17:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

long	read_long(t_client *client)
{
	long	val;

	if (read(client->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("client: can't read from socket", EXIT_FAILURE);
	return (val);
}

char	*read_str(t_client *client)
{
	char	*str;
	long	len;

	len = read_long(client);
	if (len <= 0)
		ft_exit("client: invalid str length", EXIT_FAILURE);
	str = read_mem(client, len);
	return (str);
}

void	*read_mem(t_client *client, long len)
{
	void	*mem;

	if (len <= 0)
		ft_exit("client: invalid memory length", EXIT_FAILURE);
	if (!(mem = malloc(len + 1)))
		ft_exit("client: can't malloc from read_mem", EXIT_FAILURE);
	ft_bzero(mem, len + 1);
	if (read(client->sock_fd, mem, len) != len)
		ft_exit("client: can't read from socket", EXIT_FAILURE);
	return (mem);
}

char	read_byte(t_client *client)
{
	char	val;

	if (read(client->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("client: can't read from socket", EXIT_FAILURE);
	return (val);
}
