/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:16 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 16:22:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	put_file(t_env *env, int fd)
{
	ssize_t		readed;
	char		*buff;

	if (!(buff = malloc(sizeof(*buff) * 500)))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	while ((readed = read(fd, buff, 500)) > 0)
	{
		write_long(env, readed);
		write_mem(env, buff, readed);
	}
	if (readed == -1)
		ft_putendl("ERROR: can't read file");
	write_long(env, -1);
	free(buff);
}

static int	get_mode(int fd, int *mode)
{
	struct stat	stats;

	if (fstat(fd, &stats) == -1)
		return (0);
	*mode = stats.st_mode;
	return (1);
}

static void	put_error(int error)
{
	if (result == -1)
		ft_putendl("ERROR: you don't have permissions");
	else if (result == -2)
		ft_putendl("ERROR: can't create file");
	else
		ft_putendl("ERROR: unknown error");
}

void		command_put(t_env *env, char **splitted)
{
	int			result;
	int			mode;
	int			fd;

	if (!splitted[1])
	{
		ft_putendl("ERROR: you must specify a file name");
		return ;
	}
	fd = open(splitted[1], O_RDONLY);
	if (fd == -1 || !get_mode(fd, &mode))
	{
		ft_putendl("ERROR: can't open file");
		return ;
	}
	write_long(env, 5);
	write_str(env, splitted[1]);
	write_long(env, mode);
	if ((result = read_long(env)) == 1)
		put_file(env, fd);
	else
		put_error(result);
	close(fd);
}
