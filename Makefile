# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 15:03:36 by qtamaril          #+#    #+#              #
#    Updated: 2020/10/06 13:20:14 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_A =	libft/libft.a
GNL_A = gnl/gnl.a
INCLUDE = includes/minishell.h

FLAGS_W = -Wall -Wextra -Werror -g
FLAGS_LIB = -Iincludes

DIR_SRCS = srcs
DIR_LIB = libft
DIR_INC = includes
DIR_GNL = gnl

SRCS = srcs/builtins/builtins.c \
		srcs/builtins/my_cd.c \
		srcs/builtins/my_echo.c \
		srcs/builtins/my_env.c \
		srcs/builtins/my_export.c \
		srcs/builtins/my_pwd.c \
		srcs/builtins/my_unset.c \
		srcs/commands.c \
		srcs/env.c \
		srcs/exit.c \
		srcs/main_utils.c \
		srcs/main.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re norme run

all: $(NAME)

$(NAME): $(INCLUDE) $(OBJS)
	@make -C $(DIR_GNL)
	@make -C $(DIR_LIB)
	@make bonus -C $(DIR_LIB)
	gcc $(FLAGS_W) $(LIB_A) $(GNL_A) $(OBJS) -o $(NAME)

norme:
	@make fclean
	@echo
	norminette ./$(DIR_GNL)/
	@echo
	norminette ./$(DIR_INC)
	@echo
	norminette ./$(DIR_LIB)
	@echo
	norminette ./$(DIR_SRCS)

%.o: %.c
	gcc -c $(FLAGS_LIB) $(FLAGS_W) -o $@ $<

clean:
	rm -rf $(OBJS)
	@make -C $(DIR_GNL) clean
	@make -C $(DIR_LIB) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(GNL_A)
	@make -C $(DIR_LIB) fclean

re: fclean all
