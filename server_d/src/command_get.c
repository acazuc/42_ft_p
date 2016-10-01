/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/30 23:14:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			command_get_put_file(t_client *client, int fd)
{
	ssize_t	readed;
	char	*buff;

	if (!(buff = malloc(sizeof(*buff) * 500)))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	while ((readed = read(fd, buff, 500)) > 0)
	{
		write_long(client, readed);
		write_mem(client, buff, readed);
	}
	if (readed == -1)
		write_long(client, -2);
	else
		write_long(client, -1);
	free(buff);
}

static void		get_file_name_path(char *path_name, char **path, char **file)
{
	char	*last_slash;

	last_slash = ft_strrchr(path_name, '/');
	if (!last_slash)
	{
		*path = ".";
		*file = path_name;
		return ;
	}
	*last_slash = '\0';
	*path = path_name;
	*file = last_slash + 1;
}

static int		move_to(t_client *client, char *gpath)
{
	char	*current;
	char	*new;

	if (!(current = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(current, PATH_MAX + 1);
	if (!getcwd(current, PATH_MAX))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (chdir(gpath) == -1)
	{
		free(current);
		return (0);
	}
	if (!(new = malloc(PATH_MAX + 1)))
		ft_exit("server: can't malloc", EXIT_FAILURE);
	ft_bzero(new, PATH_MAX + 1);
	if (!getcwd(new, PATH_MAX))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (ft_strstr(new, client->origin_path) != new)
	{
		command_get_2_error(new, current);
		return (0);
	}
	return (1);
}

static int		get_mode(int fd, int *mode)
{
	struct stat	stats;

	if (fstat(fd, &stats) == -1)
		return (0);
	*mode = stats.st_mode;
	return (1);
}

void			command_get(t_client *client)
{
	char	*path;
	char	*file;
	char	*tmp;
	int		mode;
	int		fd;

	get_file_name_path((tmp = read_str(client)), &path, &file);
	if (!move_to(client, path))
	{
		write_long(client, -1);
		free(tmp);
		return ;
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		command_get_2_error2(client, tmp);
		return ;
	}
	if (!get_mode(fd, &mode))
	{
		command_get_2_error3(client, fd, tmp);
		return ;
	}
	command_get_2_end(client, mode, fd, tmp);
}
