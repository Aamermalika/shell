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
void	ft_exit();
void	ft_export(t_list	 *env_vars_head, t_arguments *args);
void	call_builtins();



/*libft*/
char	**ft_split(char  *s, char c);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);

t_list	*ft_lstnew(char *first, char *second);
void	ft_lstadd_back(t_list *head , t_list *new);
#endif

