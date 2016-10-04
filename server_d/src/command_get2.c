/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 16:11:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 20:31:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		command_get_2_error(char *new, char *current)
{
	free(new);
	if (chdir(current) == -1)
		ft_exit("server: can't chdir back", EXIT_FAILURE);
	free(current);
}

void		command_get_2_error2(t_client *client, char *tmp)
{
	if (errno == ENOENT)
		write_long(client, -1);
	else if (errno == EACCES)
		write_long(client, -2);
	else
		write_long(client, -3);
	free(tmp);
}

static int	get_mode(int fd, int *mode)
{
	struct stat	stats;

	if (fstat(fd, &stats) == -1)
		return (0);
	*mode = stats.st_mode;
	return (1);
}

void		command_get_2_end(t_client *client, int fd, char *tmp)
{
	int		mode;

	if (!get_mode(fd, &mode))
	{
		command_get_2_error3(client, fd, tmp);
		return ;
	}
	write_long(client, 1);
	write_long(client, mode);
	if (read_long(client))
		command_get_put_file(client, fd);
	close(fd);
	free(tmp);
}

void		command_get_2_error3(t_client *client, int fd, char *tmp)
{
	close(fd);
	write_long(client, -3);
	free(tmp);
}
