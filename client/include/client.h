/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:46:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 11:43:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/include/libft.h"
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <limits.h>
# include <netdb.h>
# include <fcntl.h>

# ifndef SO_NOSIGPIPE
#  define SO_NOSIGPIPE 0
# endif

# define COMMAND_PWD 1
# define CONMAND_LS 2
# define COMMAND_CD 3
# define COMMAND_QUIT 4
# define COMMAND_PUT 5
# define COMMAND_GET 6

typedef struct			s_env
{
	char				*host;
	unsigned short		port;
	struct sockaddr_in	*sockaddr;
	int					sock_fd;
}						t_env;

void					parse_arguments(t_env *env, char **av);
void					resolve_host(t_env *env);
void					server_connect(t_env *env);
void					run(t_env *env);
char					*get_next_command();
void					run_command(t_env *env, char *command);
void					command_cd(t_env *env, char **splitted);
void					command_ls(t_env *env, char **splitted);
void					command_get(t_env *env, char **splitted);
void					command_put(t_env *env, char **splitted);
void					command_pwd(t_env *env, char **splitted);
void					command_quit(t_env *env, char **splitted);
long					read_long(t_env *env);
char					*read_str(t_env *env);
void					*read_mem(t_env *env, long length);
void					write_long(t_env *env, long val);
void					write_str(t_env *env, char *str);
void					write_mem(t_env *env, void *data, size_t len);

#endif
