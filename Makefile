# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/04/02 15:58:03 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft client server

libft:
	@echo " - Making libft"
	@make -C libft/

client:
	@echo " - Making client"
	@make -C client/

server:
	@echo " - Making server"
	@make -C server/

clean:
	@echo " - Cleaning libft"
	@make -C libft/ clean
	@echo " - Cleaning client"
	@make -C client/ clean
	@echo " - Cleaning server"
	@make -C server/ clean

fclean:
	@echo " - Cleaning libft executable"
	@make -C libft/ fclean
	@echo " - Cleaning client executable"
	@make -C client/ fclean
	@echo " - Cleaning server executable"
	@make -C server/ fclean

re: fclean all

.PHONY: libft client server clean fclean re
