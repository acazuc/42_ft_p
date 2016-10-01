# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/10/01 11:51:57 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft client server

libft:
	@echo " - Making libft"
	@make -C libft

client:
	@echo " - Making client"
	@make -C client_d
	@ln -sf client_d/client client

server:
	@echo " - Making server"
	@make -C server_d
	@ln -s server_d/server server

clean:
	@echo " - Cleaning libft"
	@make -C libft clean
	@echo " - Cleaning client"
	@make -C client_d clean
	@echo " - Cleaning server"
	@make -C server_d clean

fclean:
	@echo " - Cleaning libft executable"
	@make -C libft fclean
	@echo " - Cleaning client executable"
	@make -C client_d fclean
	@echo " - Cleaning server executable"
	@make -C server_d fclean
	@rm -f client
	@rm -f server

re: fclean all

.PHONY: libft client server clean fclean re
