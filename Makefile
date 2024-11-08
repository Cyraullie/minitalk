# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/08 13:38:03 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = ./libft/libft.a
RM = rm -rf

SRV_SRCS = srcs/
CLI_SRCS = srcs/

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)

# Règles
all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -I -c -o $@ $<

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)
$(SERVER): $(SRV_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT) -o server
$(CLIENT): $(CLI_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_OBJS) $(LIBFT) -o client


clean:
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(SV_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
