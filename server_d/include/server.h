/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:52:25 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/07 11:22:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/include/libft.h"
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <limits.h>
# include <netdb.h>
# include <errno.h>
# include <dirent.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

# ifndef SO_NOSIGPIPE
#  define SO_NOSIGPIPE 0
# endif

# define COMMAND_PWD 1
# define COMMAND_LS 2
# define COMMAND_CD 3
# define COMMAND_QUIT 4
# define COMMAND_PUT 5
# define COMMAND_GET 6
# define COMMAND_TOUCH 7
# define COMMAND_UNLINK 8

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
char					read_byte(t_client *client);
void					write_long(t_client *client, long val);
void					write_str(t_client *client, char *str);
void					write_mem(t_client *client, void *data, size_t len);
void					write_byte(t_client *client, char val);
void					run_client(int fd);
void					command_pwd(t_client *client);
void					command_put(t_client *client);
void					command_ls(t_client *client);
void					command_get(t_client *client);
void					command_get_2_error(char *new, char *current);
void					command_get_2_error2(t_client *client, char *tmp);
void					command_get_2_end(t_client *client, int fd
		, char *tmp);
void					command_get_2_error3(t_client *client, int fd
		, char *tmp);
void					command_get_put_file(t_client *client, int fd);
void					command_cd(t_client *client);
void					command_touch(t_client *client);
void					command_unlink(t_client *client);
char					*remove_last_slash(char *str);
void					ls_replace_args(t_client *client, char **args);
char					*replace_start_slash(t_client *client, char *str);
void					ls_replace_arg_2(t_client *client, char **arg
		, int is_dir, char *name);

#endif
