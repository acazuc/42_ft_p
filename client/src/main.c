/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 15:45:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/05/21 15:47:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int ac, char **av)
{
	t_env	env;

	if (ac < 3)
		ft_exit("client: invalid arguments\nclient <host> <port>"
				, EXIT_FAILURE);
	parse_arguments(&env, av);
	resolve_host(&env);
	server_connect(&env);
	run(&env);
}
