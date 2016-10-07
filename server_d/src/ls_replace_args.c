/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_replace_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:43:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/07 11:22:59 by acazuc           ###   ########.fr       */
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

static int		is_directory(char *file)
{
	struct stat	sstat;

	if (stat(file, &sstat) == -1)
		return (0);
	if (S_ISDIR(sstat.st_mode))
		return (1);
	return (0);
}

static int		invalid_path(t_client *client, char *path)
{
	char	*orig;
	char	*new;
	int		ret;

	if (!(orig = getcwd(NULL, 0)))
		ft_exit("getcwd failed", EXIT_FAILURE);
	if (chdir(path) == -1)
	{
		free(orig);
		return (0);
	}
	if (!(new = getcwd(NULL, 0)))
		ft_exit("getcwd failed", EXIT_FAILURE);
	ret = 0;
	if (ft_strstr(new, client->origin_path) != new)
		ret = 1;
	if (chdir(orig) == -1)
		ft_exit("can't chdir to original path", EXIT_FAILURE);
	free(orig);
	return (ret);
}

static void		replace_arg(t_client *client, char **arg)
{
	char	*orig;
	char	*path;
	char	*name;
	int		is_dir;

	if (!(orig = ft_strdup(*arg)))
		ft_exit("ft_strdup failed", EXIT_FAILURE);
	*arg = remove_last_slash(*arg);
	if ((is_dir = is_directory(*arg)))
	{
		path = *arg;
		name = ".";
	}
	else
		get_file_name_path(*arg, &path, &name);
	if (invalid_path(client, path))
	{
		free(orig);
		ls_replace_arg_2(client, arg, is_dir, name);
	}
	else
	{
		free(*arg);
		*arg = orig;
	}
}

void			ls_replace_args(t_client *client, char **av)
{
	int		yep;
	int		i;

	yep = 0;
	i = 1;
	while (av[i])
	{
		if (yep)
		{
			av[i] = replace_start_slash(client, av[i]);
			replace_arg(client, &av[i]);
		}
		else
		{
			if (av[i][0] != '-')
			{
				yep = 1;
				i--;
			}
		}
		i++;
	}
}
