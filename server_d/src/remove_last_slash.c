/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last_slash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 13:26:36 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/01 13:37:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char		*return_val(char *str, ssize_t i)
{
	char	*tmp;

	if (i == -1)
	{
		if (!(tmp = ft_strnew(0)))
			ft_exit("ft_strnew failed", EXIT_FAILURE);
	}
	else
	{
		str[i + 1] = '\0';
		if (!(tmp = ft_strdup(str)))
			ft_exit("ft_strdup failed", EXIT_FAILURE);
	}
	free(str);
	return (tmp);
}

char			*remove_last_slash(char *str)
{
	ssize_t	i;

	if (!(str = ft_strtrim_free(str)))
		ft_exit("ft_strtrim failed", EXIT_FAILURE);
	i = ft_strlen(str);
	while (--i > 0)
	{
		if (str[i] != '/')
			break ;
	}
	return (return_val(str, i));
}
