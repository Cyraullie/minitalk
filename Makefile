# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/19 13:51:55 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_B = server
CLIENT_B = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = ./libft/libft.a
RM = rm -rf

SRV_SRCS = src/server.c
CLI_SRCS = src/client.c

SRV_B_SRCS = src_bonus/server_bonus.c
CLI_B_SRCS = src_bonus/client_bonus.c

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)

SRV_B_OBJS = $(SRV_B_SRCS:.c=.o)
CLI_B_OBJS = $(CLI_B_SRCS:.c=.o)

# Règles
all: $(SERVER) $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)
$(SERVER): $(SRV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLI_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_OBJS) $(LIBFT) -o client

$(SERVER_B): $(SRV_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_B_OBJS) $(LIBFT) -o server
$(CLIENT_B): $(CLI_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_B_OBJS) $(LIBFT) -o client

clean:
	$(MAKE) clean -s -C $(LIBFT_PATH)
	$(RM) $(SRV_OBJS) $(CLI_OBJS)
	$(RM) $(SRV_B_OBJS) $(CLI_B_OBJS)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT_PATH) 
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
