/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:41 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 16:15:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	write_long(t_client *client, long val)
{
	if (write(client->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("server: can't write long value", EXIT_FAILURE);
}

void	write_str(t_client *client, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	write_long(client, len + 1);
	write_mem(client, str, len + 1);
}

void	write_mem(t_client *client, void *data, size_t len)
{
	if (write(client->sock_fd, data, len) != (ssize_t)len)
		ft_exit("server: can't write mem value", EXIT_FAILURE);
}

void	write_byte(t_client *client, char val)
{
	if (write(client->sock_fd, &val, sizeof(val)) != sizeof(val))
		ft_exit("server: can't write to socket", EXIT_FAILURE);
}
