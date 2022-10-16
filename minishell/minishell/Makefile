# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maamer <maamer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 11:02:02 by mel-amma          #+#    #+#              #
#    Updated: 2022/10/16 14:22:35 by maamer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c helpers.c helpers2.c  wildcard.c  builtins.c execution.c linked.c libft.c exec.c
NAME = minishell
FLAG =  -L/usr/local/lib -I/usr/local/include -lreadline -g -fsanitize=address  #-lreadline -L /Users/mel-amma/Deskt/homebrew/opt/readline/lib -I /Users/mel-amma/Desktop/homebrew/opt/readline/include  -lncurses -g
#!-Wall -Wextra -Werror!#op
all : $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAG) $(SRC) -o $(NAME)
clean:
	@rm -rf $(NAME)
fclean: clean
re : fclean all
.PHONY: all clean fclean re