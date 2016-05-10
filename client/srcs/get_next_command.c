#include "client.h"

static void	init(char **buff, char **resu)
{
	if (!(*buff = malloc(sizeof(**buff) * 50)))
	{
		ft_putendl_fd("client: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(*buff, 50);
	if (!(*resu = malloc(sizeof(**resu))))
	{
		ft_putendl_fd("client: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	**resu = '\0';
}

char		*get_next_command()
{
	ssize_t	readed;
	char	*buff;
	char	*resu;

	init(&buff, &resu);
	while ((readed = read(0, buff, 49)) > 0)
	{
		if (!(resu = ft_strjoin_free1(resu, buff)))
		{
			ft_putendl_fd("client: can't join buffer", 2);
			exit(EXIT_FAILURE);
		}
		if (buff[ft_strlen(buff) - 1] == '\n')
			break;
		ft_bzero(buff, 50);
	}
	free(buff);
	if (readed == -1)
	{
		ft_putendl_fd("client: failed to read stdin", 2);
		exit(EXIT_FAILURE);
	}
	if (!(buff = ft_strtrim(resu)))
	{
		ft_putendl_fd("cilent: failed to trim command", 2);
		exit(EXIT_FAILURE);
	}
	return (buff);
}
