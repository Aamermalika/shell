/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:55:41 by maamer            #+#    #+#             */
/*   Updated: 2022/09/20 15:38:37 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "minishell.h"


void free_env_value(t_list *node)
{
	free(node->value);
	node->value = 0;
}

char **duplicate_envirement_var(char **env)
{
	int env_vars_count;
	char **array;
	int i;

	i = 0;
	env_vars_count = 0;
	while (env[env_vars_count])
		env_vars_count++;

	array = malloc(sizeof(char *) * (env_vars_count + 1));

	while (i < env_vars_count)
	{
		array[i] = ft_strdup(env[i]);
		i++;
	}
	array[i] = 0;

	return array;
}
 
char *first_half(char *str)
{
	int	i = 0;
	char *p;
	while(str[i] != '=')
		i++;
	p = ft_substr(str, 0, i);
	return(p);
}

char *second_half(char *str)
{
	int		i;
	char	*p;

	i = 0;
	while(str[i])
	{
		if(str[i] == '=')
			p = ft_substr(str, i+1, ft_strlen(str));
		i++;
	}
	return(p);
}

t_list *env_vars_list(char **env)
{
	t_list	*lst;
	t_list *tmp = NULL;
	int		i = 1;
	int env_vars_count;
	t_list *new_node;

	env_vars_count = 0;
	while (env[env_vars_count])
		env_vars_count++;
	if (env_vars_count)
	{
		lst = ft_lstnew(first_half(env[0]), second_half(env[0]));
		tmp = lst;
		while(i < env_vars_count)
		{
			new_node = ft_lstnew(first_half(env[i]), second_half(env[i]));
			ft_lstadd_back(lst, new_node);
			lst = lst->next;
			i++;
		}
	}
	lst = tmp;
	return (tmp);
}

void	ft_export(t_list	 *env_vars_head, t_arguments *args)
{
	
	char *first;
	//char *second;
	printf("%s\n",env_vars_head->key);
	
	// v_lines->env_vars_head : head of the env list
	int flagPlusEq = 0;
	while(args)
	{
		first = first_half(args->arg);
		printf("first----->%s",first);
		//printf()

		//found += >> search in envhead first + secondhalf 
		flagPlusEq = 1;
		
		//tmp = join old second new second;
		//free current second
		//second = tmp;
		//second = second_half(args->arg);
		
		//make new node with first second and addback to head
		
		//printf("declare -x %s\n",env_vars_head->key);
		args = args->next;
	}
}

void	call_builtins()
{
	char *command;

	command = v_lines->command_table->command;
	if(((!ft_strncmp(command, "cd", max(2,ft_strlen(command))) || (!ft_strncmp(command, "CD", max(2,ft_strlen(command))))) && ft_strlen(command) == 2))
		ft_cd(v_lines->command_table->argument);
	else if(((!ft_strncmp(command, "pwd", max(3,ft_strlen(command))) || (!ft_strncmp(command, "PWD", max(3,ft_strlen(command))))) && ft_strlen(command) == 3))
		ft_pwd();
	else if(((!ft_strncmp(command, "env", max(3,ft_strlen(command))) || (!ft_strncmp(command, "ENV", max(3,ft_strlen(command))))) && ft_strlen(command) == 3))
		ft_env();
}

//int main(int ac, char **av ,char **env)
// {
// 	(void)ac;
// 	(void)av;
	//char *p;
	//char **split;
	//t_arguments *lst = NULL;
	//t_list *env_vars_head;
	//char **env_duplicate_array;

	// printf("jhkjfjkafl");
	// env_duplicate_array = duplicate_envirement_var(env);
	// env_vars_head = env_vars_list(env_duplicate_array);
	//exit(0);
	//printf("======%p\n",lst->arg);
	//ft_export(env_vars_head,);
	//while(1)
	//{
		//p = readline("minishell> ");
		//add_history(p);
		//split = ft_split(p, ' ');
		// if(((!ft_strncmp(split[0], "cd", 2) || (!ft_strncmp(split[0], "CD", 2))) && ft_strlen(split[0]) == 2))
		// 	ft_cd(split);
		// else if(((!ft_strncmp(split[0], "pwd", 3) || (!ft_strncmp(split[0], "PWD", 3))) && ft_strlen(split[0]) == 3))
		// 	ft_pwd();
		// else if(((!ft_strncmp(split[0], "env", 3) || (!ft_strncmp(split[0], "ENV", 3))) && ft_strlen(split[0]) == 3))
		// 	ft_env(env);
		
		//  if(!ft_strncmp(split[0], "export", 6) && ft_strlen(split[0]) == 6)
		// {
		// 	ft_export(env_vars_head,);
		// }
		// else
	//	// 	printf("mini: %s: command not founnd\n", split[0]);
	//}
//}
