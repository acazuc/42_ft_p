/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:14 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/04 17:32:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	tab_len(char **splitted)
{
	int		i;

	i = 1;
	while (splitted[i])
		++i;
	return (i - 1);
}

void		command_ls(t_env *env, char **splitted)
{
	long	i;
	char	c;

	write_long(env, COMMAND_LS);
	write_long(env, tab_len(splitted));
	i = 1;
	while (splitted[i])
		write_str(env, splitted[i++]);
	while ((c = read_byte(env)))
		ft_putchar(c);
	ft_putendl("SUCCESS");
	(void)splitted;
}
