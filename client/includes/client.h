#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/includes/libft.h"
# include <netinet/in.h>
# include <sys/socket.h>
# include <limits.h>
# include <netdb.h>

typedef struct		s_env
{
	char				*host;
	unsigned short		port;
	struct sockaddr_in *sockaddr;
	int					sock_fd;
}						t_env;

void	parse_arguments(t_env *env, char **av);
void	resolve_host(t_env *env);
void	server_connect(t_env *env);
void	run(t_env *env);
char	*get_next_command();
void	run_command(t_env *env, char *command);
void	command_cd(t_env *env, char **splitted);
void	command_ls(t_env *env, char **splitted);
void	command_get(t_env *env, char **splitted);
void	command_put(t_env *env, char **splitted);
void	command_pwd(t_env *env, char **splitted);
void	command_quit(t_env *env, char **splitted);

#endif
