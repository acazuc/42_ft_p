/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_unlink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:32:48 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 13:16:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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

static void			put_error_free(t_client *client, char *tmp)
{
	free(tmp);
	if (errno == ENOENT)
		write_long(client, -2);
	else if (errno == EACCES || errno == EROFS || errno == EPERM)
		write_long(client, -4);
	else
		write_long(client, -5);
}

static int			check_dir(t_client *client, char *file)
{
	struct stat	sstat;

	if (stat(file, &sstat) == -1)
	{
		put_error_free(client, file);
		free(file);
		return (0);
	}
	if (S_ISDIR(sstat.st_mode))
	{
		write_long(client, -3);
		free(file);
		return (0);
	}
	return (1);
}

void				command_unlink(t_client *client)
{
	char		*path;
	char		*file;
	char		*tmp;

	get_file_name_path((tmp = read_str(client)), &path, &file);
	if (!move_to(client, path))
	{
		write_long(client, -1);
		free(tmp);
		return ;
	}
	if (!check_dir(client, tmp))
		return ;
	if (unlink(tmp) == -1)
	{
		put_error_free(client, tmp);
		return ;
	}
	free(tmp);
	write_long(client, 1);
}
