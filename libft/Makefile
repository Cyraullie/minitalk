# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/11 14:19:13 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I
INCLUDES	=	./
SRC = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_printf_utils1.c ft_printf_utils2.c ft_printf.c \
	  get_next_line_utils.c get_next_line.c handle_error.c
SRCBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		   ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)
NAME = libft.a
# Règles
all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(OBJBONUS)
	ar rc $(NAME) $(OBJ) $(OBJBONUS)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

bonus: $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus
