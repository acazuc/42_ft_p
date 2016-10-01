/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:12 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 11:42:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char		*get_file_name(char *file)
{
	char	*tmp;

	tmp = ft_strrchr(file, '/');
	if (!tmp)
		return (ft_strdup(file));
	tmp = ft_strdup(tmp + 1);
	free(file);
	return (tmp);
}

static void		read_file(t_env *env, int fd)
{
	long	tmp;
	char	*data;

	while ((tmp = read_long(env)) >= 0)
	{
		data = read_mem(env, tmp);
		tmp = write(fd, data, tmp);
	}
	if (tmp == -2)
		ft_putendl("ERROR: error while reading file");
	else if (tmp == -1)
		ft_putendl("SUCCESS");
}

static void		do_the_thing(t_env *env, char **splitted)
{
	char	*file;
	int		fd;

	file = get_file_name(splitted[1]);
	if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY
					, (int)read_long(env))) == -1)
	{
		write_long(env, 0);
		ft_putendl("ERROR: can't create file");
		return ;
	}
	write_long(env, 1);
	read_file(env, fd);
	close(fd);
	free(file);
}

void			command_get(t_env *env, char **splitted)
{
	int		res;

	write_long(env, COMMAND_GET);
	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a file to get");
		return ;
	}
	write_str(env, splitted[1]);
	if ((res = read_long(env)) == -1)
		ft_putendl("ERROR: file not found");
	else if (res == -2)
		ft_putendl("ERROR: permissions denied");
	else if (res == -3)
		ft_putendl("ERROR: unknown error");
	else
		do_the_thing(env, splitted);
}
