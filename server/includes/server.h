/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:52:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 16:02:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/includes/libft.h"
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <limits.h>
# include <netdb.h>
# include <errno.h>
# include <dirent.h>
# include <fcntl.h>

typedef struct			s_env
{
	int					port;
	int					sock_fd;
	struct sockaddr_in	sockaddr;
}						t_env;

typedef struct			s_client
{
	char				*origin_path;
	int					sock_fd;
}						t_client;

void					run(t_env *env);
void					build_host(t_env *env);
void					parse_parameters(t_env *env, char **av);
long					read_long(t_client *client);
char					*read_str(t_client *client);
void					*read_mem(t_client *client, long len);
void					write_long(t_client *client, long val);
void					write_str(t_client *client, char *str);
void					write_mem(t_client *client, void *data, size_t len);
void					run_client(int fd);
void					command_pwd(t_client *client);
void					command_put(t_client *client);
void					command_ls(t_client *client);
void					command_get(t_client *client);
void					command_cd(t_client *client);

#endif
