# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kennahi <kennahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 10:06:40 by ybouddou          #+#    #+#              #
#    Updated: 2021/09/28 18:09:44 by kennahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIB = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_C =	client.c\

SRC_S =	server.c\

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)

all: lib $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_C)
	@$(CC) $(OBJ_C) $(LIB) -o $(CLIENT)
	
$(SERVER): $(OBJ_S)
	@$(CC) $(OBJ_S) $(LIB) -o $(SERVER)

lib:
	@make -C Libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C Libft/
	@rm -rf $(OBJ_S) $(OBJ_C)

fclean: clean
	@make fclean -C Libft/
	@rm -rf $(CLIENT) $(SERVER)

re: fclean all
