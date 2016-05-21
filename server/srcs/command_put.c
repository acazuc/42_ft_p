/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:19 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:55:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*get_file_name(char *file)
{
	char	*tmp;

	tmp = ft_strrchr(file, '/');
	if (!tmp)
		return (file);
	tmp = ft_strdup(tmp);
	free(file);
	return (tmp);
}

static void	read_file(t_client *client, int fd)
{
	long	tmp;
	char	*data;

	while ((tmp = read_long(client)) >= 0)
	{
		data = read_mem(client, tmp);
		tmp = write(fd, data, tmp);
	}
}

void		command_put(t_client *client)
{
	char	*file;
	int		fd;

	file = read_str(client);
	file = get_file_name(file);
	if (!(file = ft_strjoin_free2("./", file)))
		ft_exit("server: can't join file name", EXIT_FAILURE);
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		if (errno == EACCES)
			write_long(client, -1);
		else
			write_long(client, -2);
		free(file);
		return ;
	}
	free(file);
	write_long(client, 1);
	read_file(client, fd);
	close(fd);
	(void)client;
}
