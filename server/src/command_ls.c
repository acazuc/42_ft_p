/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:54:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 11:45:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	command_ls(t_client *client)
{
	DIR				*dir;
	struct dirent	*dirent;

	if (!(dir = opendir(".")))
	{
		write_long(client, -1);
		return ;
	}
	write_long(client, 0);
	while ((dirent = readdir(dir)))
	{
		write_str(client, dirent->d_name);
	}
	closedir(dir);
	write_str(client, "");
}
