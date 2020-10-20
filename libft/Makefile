# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/15 12:22:12 by qtamaril          #+#    #+#              #
#    Updated: 2020/10/17 16:08:41 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERS = libft.h

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strcmp.c ft_str_realloc.c ft_free_strstr.c \
				ft_strstrdup.c ft_strstrlen.c ft_strcpy.c ft_str_is_num.c \
				ft_strstr_realloc.c ft_putstrstr_fd.c ft_lst_remove_if.c \
				ft_strlowcase.c ft_isspace.c ft_issymbol.c ft_lstnew.c  \
				ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				ft_strjoin_gnl.c

OBJS = $(SRCS:%.c=%.o)

RM = rm -f
AR = ar rc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
