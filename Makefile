# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/25 13:53:25 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_B = server_b
CLIENT_B = client_b

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = ./libft/libft.a
RM = rm -rf

SRV_SRCS = src/server.c src/string.c
CLI_SRCS = src/client.c src/string.c

SRV_B_SRCS = src_bonus/server_bonus.c
CLI_B_SRCS = src_bonus/client_bonus.c

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)

SRV_B_OBJS = $(SRV_B_SRCS:.c=.o)
CLI_B_OBJS = $(CLI_B_SRCS:.c=.o)

# Règles
all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)

$(SERVER): $(SRV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLI_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_OBJS) $(LIBFT) -o $(CLIENT)

bonus: $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SRV_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_B_OBJS) $(LIBFT) -o $(SERVER_B)

$(CLIENT_B): $(CLI_B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_B_OBJS) $(LIBFT) -o $(CLIENT_B)

clean:
	$(MAKE) clean -s -C $(LIBFT_PATH)
	$(RM) $(SRV_OBJS) $(CLI_OBJS)
	$(RM) $(SRV_B_OBJS) $(CLI_B_OBJS)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT_PATH) 
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
