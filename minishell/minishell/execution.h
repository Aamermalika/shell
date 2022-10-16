#ifndef EXECUTION_H
# define EXECUTION_H

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*  next;
}		t_list;

/*builtins*/
void	exec();
void	ft_pwd();
void	ft_env();
void	ft_cd();
void	ft_unset();
void	ft_exit(t_arguments *args);
void	ft_export(t_arguments *args);
void	ft_echo();
int	n_arg_check(t_arguments *args);
int is_built_in(t_line_processing_history *v_lines);


char *first_half(char *str);
char *second_half(char *str);
int	args_types(char *str);

/*libft*/
char	**ft_split(char  *s, char c);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

/*pipe*/
char	**parsing_path(char *command);
void correct_access(t_commandtable *command_table);
int	commande_with_path(t_commandtable *commande);
int execute(t_line_processing_history *v_lines);

/*liked_list*/
t_list	*ft_lstnew(char *first, char *second);
void	ft_lstadd_back(t_list *head , t_list *new);
t_list	*del_node(t_list *list_head, t_list *node_2_delete);
void	ft_lstadd_back1(t_list **head , t_list *new);
int ft_lstsize(t_arguments *lst);
#endif

