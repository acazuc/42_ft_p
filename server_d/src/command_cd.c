/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:09 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/30 23:11:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		error_1(t_client *client, char *gpath, char *current)
{
	if (errno == EACCES)
		write_long(client, -2);
	else if (errno == ENOENT)
		write_long(client, -1);
	else if (errno == ENOTDIR)
		write_long(client, -4);
	else
		write_long(client, -3);
	free(gpath);
	free(current);
}

static void		error_2(t_client *client, char *gpath, char *new, char *current)
{
	free(gpath);
	free(new);
	if (chdir(current) == -1)
		ft_exit("server: can't chdir back", EXIT_FAILURE);
	free(current);
	write_long(client, -2);
}

void			command_cd(t_client *client)
{
	char	*current;
	char	*gpath;
	char	*new;

	if (!(current = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(current, PATH_MAX + 1);
	if (!getcwd(current, PATH_MAX))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (chdir((gpath = read_str(client))) == -1)
	{
		error_1(client, gpath, current);
		return ;
	}
	if (!(new = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(new, PATH_MAX + 1);
	if (!getcwd(new, PATH_MAX))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (ft_strstr(new, client->origin_path) != new)
	{
		error_2(client, gpath, new, current);
		return ;
	}
	write_long(client, 0);
}
