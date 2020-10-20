# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtamaril <qtamaril@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 15:03:36 by qtamaril          #+#    #+#              #
#    Updated: 2020/10/18 12:51:37 by qtamaril         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_A =	libft/libft.a
INCLUDE = includes/minishell.h libft/libft.h

FLAGS_W = -Wall -Wextra -Werror -g
FLAGS_LIB = -Iincludes

DIR_SRCS = srcs
DIR_LIB = libft
DIR_INC = includes

SRCS = srcs/builtins/builtins.c \
		srcs/builtins/my_cd.c \
		srcs/builtins/my_cd_utils.c \
		srcs/builtins/my_echo.c \
		srcs/builtins/my_env.c \
		srcs/builtins/my_exit.c \
		srcs/builtins/my_export.c \
		srcs/builtins/my_pwd.c \
		srcs/builtins/my_unset.c \
		srcs/errors/error.c \
		srcs/errors/error2.c \
		srcs/errors/error3.c \
		srcs/commands.c \
		srcs/directions.c \
		srcs/directions_utils.c \
		srcs/env.c \
		srcs/utils.c \
		srcs/main.c \
		srcs/lookup_env.c \
		srcs/parse_line.c \
		srcs/parse_arg.c \
		srcs/check_path.c \
		srcs/check_tokens.c \
		srcs/signals.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re norme run libft_make

all: libft_make $(NAME)

$(NAME): $(INCLUDE) $(OBJS)
	@clang $(FLAGS_W) $(LIB_A) $(OBJS) -o $(NAME)
	@echo minishell ready for work

norme:
	@make fclean
	@echo
	norminette ./$(DIR_INC)
	@echo
	norminette ./$(DIR_LIB)
	@echo
	norminette ./$(DIR_SRCS)

%.o: %.c $(INCLUDE)
	@clang $(FLAGS_W) $(FLAGS_LIB) -c $< -o $@

libft_make:
	@make -C $(DIR_LIB) --silent
	@echo libft builded


clean:
	rm -rf $(OBJS)
	@make -C $(DIR_LIB) clean

fclean: clean
	@rm -f $(NAME) --silent
	@make -C $(DIR_LIB) fclean --silent

re: fclean all
