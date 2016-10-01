/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:48:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	init(char **buff, char **resu)
{
	if (!(*buff = malloc(sizeof(**buff) * 50)))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	ft_bzero(*buff, 50);
	if (!(*resu = malloc(sizeof(**resu))))
		ft_exit("client: can't malloc", EXIT_FAILURE);
	**resu = '\0';
}

char		*get_next_command(void)
{
	ssize_t	readed;
	char	*buff;
	char	*resu;

	init(&buff, &resu);
	while ((readed = read(0, buff, 49)) > 0)
	{
		if (!(resu = ft_strjoin_free1(resu, buff)))
			ft_exit("client: can't join buffer", EXIT_FAILURE);
		if (buff[ft_strlen(buff) - 1] == '\n')
			break ;
		ft_bzero(buff, 50);
	}
	free(buff);
	if (readed == -1)
		ft_exit("client: failed to read stdin", EXIT_FAILURE);
	if (!(buff = ft_strtrim(resu)))
		ft_exit("cilent: failed to trim command", EXIT_FAILURE);
	return (buff);
}
