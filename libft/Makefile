# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/15 12:22:12 by qtamaril          #+#    #+#              #
#    Updated: 2020/10/04 16:48:28 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME_SO		= libft.so
HEADERS = libft.h
DIR_OBJ_SO	= obj_so

SRCS_SO		= $(shell find . -type f -name 'ft_*.c')
OBJS_SO		= $(addprefix $(DIR_OBJ_SO)/,$(SRCS_SO:%.c=%.o))

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strcmp.c ft_realloc.c ft_free_strstr.c \
				ft_strstrdup.c ft_strstrlen.c ft_strcpy.c ft_str_is_num.c \
				ft_strstr_realloc.c ft_putstrstr_fd.c ft_lst_remove_if.c
OBJS = $(SRCS:%.c=%.o)
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
RM = rm -f
AR = ar rc

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	ar rc $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(HEADERS)
	ar rc $(NAME) $(BONUS_OBJS)

so: $(NAME_SO)

$(NAME_SO): $(OBJS_SO)
	gcc -shared -o $(NAME_SO) $(OBJS_SO)

$(DIR_OBJ_SO)/%.o : %.c
	@mkdir -p $(dir $@)
	gcc -Wall -Wextra -Werror -fpic -I. -o $@ -c $<

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -rf $(OBJS) $(DIR_OBJ) $(DIR_OBJ_SO)
	rm -rf *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_SO)

re: fclean all
