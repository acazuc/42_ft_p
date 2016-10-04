/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 21:36:33 by acazuc           ###   ########.fr       */
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

	if (!(current = getcwd(NULL, 0)))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (chdir(gpath) == -1)
	{
		free(current);
		return (0);
	}
	if (!(new = getcwd(NULL, 0)))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	if (ft_strstr(new, client->origin_path) != new
			&& chdir(client->origin_path) == -1)
	{
		command_get_2_error(new, current);
		return (0);
	}
	return (1);
}

void			command_get(t_client *client)
{
	char	*path;
	char	*file;
	char	*tmp;
	char	*crt;
	int		fd;

	if (!(crt = getcwd(NULL, 0)))
		ft_exit("server: can't getcwd", EXIT_FAILURE);
	tmp = remove_last_slash(read_str(client));
	tmp = replace_start_slash(client, tmp);
	get_file_name_path(tmp, &path, &file);
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
	command_get_2_end(client, fd, tmp);
	if (chdir(crt) == -1)
		ft_exit("server: can't go back to old cwd", EXIT_FAILURE);
}
