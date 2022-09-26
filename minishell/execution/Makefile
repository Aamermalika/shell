
src = *.c 
minishell = minishell
CFLAGS = -Wall -Wextra -Werror  -L/usr/local/lib -I/usr/local/include -lreadline
CC = cc

all : minishell
	
$(minishell): $(src)	
	@$(CC) $(CFLAGS) $(src) -o minishell
	@tput setaf 2; echo "minishell IS READY"

clean :
	@rm -f minishell
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all