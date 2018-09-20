# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mndlovu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/02 14:43:08 by mndlovu           #+#    #+#              #
#    Updated: 2017/09/07 16:40:37 by mndlovu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = gcc -Wall -Wextra -Werror

SRC = main.c exec_cmd.c my_environ.c echo_b.c setenv_b.c cd_b.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(FLAGS) -c $(SRC)
	@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

norm:
	@echo "\033[32m  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[32m%##############| 0.00% |#################%\033[0m"
	@norminette $(SRC) minishell.h
	@echo "\033[32m%##############| 100%  |#################%\033[0m"
	@echo "\033[32m  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"