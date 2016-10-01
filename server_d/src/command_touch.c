/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:56:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 12:04:24 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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

void				command_touch(t_client *client)
{
	char	*path;
	char	*file;
	char	*tmp;
	int		fd;

	get_file_name_path((tmp = read_str(client)), &path, &file);
	if (!move_to(client, path))
	{
		write_long(client, -1);
		free(tmp);
		return ;
	}
	if ((fd = open(file, O_CREATE | O_RDONLY)) == -1)
	{
		write_long(client, -2);
		free(tmp);
		return ;
	}
	close(fd);
	write_long(client, 1);
}
