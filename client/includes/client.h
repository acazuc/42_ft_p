#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/includes/libft.h"
# include <limits.h>

typedef struct	s_env
{
	char			*host;
	unsigned short	port;
}				t_env;

void	parse_arguments(t_env *env, char **av);

#endif
