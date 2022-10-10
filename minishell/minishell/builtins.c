/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:35:27 by maamer            #+#    #+#             */
/*   Updated: 2022/10/10 14:29:04 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "minishell.h"

void	exec()
{
	int id;
	char  *a[] = { "/bin/ls","-la", NULL};
	id = fork();
	if(!id)
	{	
		signal(SIGINT, SIG_DFL);
		if((execve(a[0], a, NULL)) == -1)
		{
			perror("execve");
			exit(0);
		}
	}
}

void	ft_pwd()
{
	char str[10000];
	char *p;
	p = getcwd(str,100);
	if(!p)
		perror("getcwd() error");
	else
		printf("%s\n",str);

}

void	ft_env()
{
	t_list *head = v_lines->env_vars_head;
	while(head)
	{
		if(head->value)
		{
			printf("%s=",head->key);
			printf("%s",head->value);
			printf("\n");
		}
		head = head->next;	
	}
}

void	old_pwd_env()
{
	char *new_old_pwd = NULL;
	char str[10000];
	char *current_directory;
	
	t_list *head = v_lines->env_vars_head;
	while(head)
	{
		if(!(ft_strncmp(head->key, "PWD", max(ft_strlen(head->key), 3))))
		{
			new_old_pwd = head->value;
			current_directory = getcwd(str,100);
			if(current_directory)
				current_directory = ft_strdup(current_directory);
			head->value = current_directory;
		}
		if(!(ft_strncmp(head->key, "OLDPWD", max(6,ft_strlen(head->key)))))
		{
			if(head->value)
				free(head->value);
			head->value = new_old_pwd;
		}
		head = head->next;
	}
}

void	ft_unset()
{
	t_arguments *args;
	t_list	*head;
		
	args = v_lines->command_table->argument;
	while (args)
	{
		head = v_lines->env_vars_head;
		while(head)
		{
			if(!ft_strncmp(args->arg, head->key, max(ft_strlen(args->arg), ft_strlen(head->key))))
				{
					head = del_node(v_lines->env_vars_head, head);
					continue;
				}
			head = head->next;
		}
		args = args->next;
	}
}
char	*cd_home()
{
	t_list	*head;
	
	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(head->key, "HOME", max(ft_strlen(head->key), ft_strlen("HOME"))))
			return(head->value);
		head = head->next;
	}
	return(NULL);
}

void	ft_cd()
{
	t_arguments *args;
	int flag;

	args = v_lines->command_table->argument;
	flag = 0;
	if (args == NULL)
	{
		flag = chdir(cd_home());
		if(flag == -1)
				perror("chdir");
	}
	else if(args->arg[0] == '~' && ft_strlen(args->arg) == 1)
	{
		flag = chdir(cd_home());
		if(flag == -1)
			perror("cd");
	}
	else if (chdir(args->arg) == -1)
	{
		perror("cd");
		flag = -1;
	}
	if(flag != -1)
		old_pwd_env();
}

int	n_arg_check(t_arguments *args)
{
	int i = 1;
	if(!args)
		return(0);
	if(args->arg[0] == '-' && args->arg[1] != 0)
	{
		while(args->arg[i])
		{
			if(args->arg[i] != 'n')
				return(0);
			i++;
		}
		return(1);
	}
	return(0);
}

void	ft_echo(t_arguments	*args)
{
	int	n_flag = 1; // if optin -n exist
	int new_line = 1; // if new_line exist

	while(n_flag == 1)
	{
		n_flag = n_arg_check(args);
		if(n_flag == 1)
			new_line = 0;
		if(n_flag == 1)
		args = args->next;
	}
	while(args)
	{ 
		printf("%s", args->arg);
		if(args->next)
			printf(" ");
		args = args->next;
	}
	if(new_line == 1)
		printf("\n");
}

int is_higher(char *str1, char *str2)
{
	if(ft_strncmp(str1, str2, max(ft_strlen(str1),ft_strlen(str2))) > 0)
		return 1;
	return 0;
}

int	env_numb(t_list *head)
{
	int	env_var_numb = 0;
	while(head)
	{
		head = head->next;
		env_var_numb++;
	}
	return(env_var_numb);
}

char	**sort(t_list *head)
{
	char **arr;
	int env_var_numb;
	int i = 0;
	env_var_numb = env_numb(head);
	arr = malloc(sizeof(char *) * (env_var_numb + 1));
	while(i < env_var_numb)
	{
		arr[i] = head->key;
		i++;
		head = head->next;
	}
	head = v_lines->env_vars_head;
	i = 1;
	char *tmp;
	while(i < env_var_numb)
	{
		int j = 0;
		while (j < env_var_numb - 1)
		{
			if(is_higher(arr[j], arr[j + 1]))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return(arr);
}

void	print_env(char *arr)
{
	t_list	*head;

	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(arr, head->key, max(ft_strlen(arr), ft_strlen(head->key))))
		{
			if(head->value)
				printf("declare -x %s=\"%s\" \n", head->key, head->value);
			else
				printf("declare -x %s\n", head->key);
		}
		head = head->next;
	}
}

int	args_types(char *str)
{
	int	i;

	i = 1;
	if(!ft_isalpha(str[0]) && str[0] != '_')
		return(0);
	while(str[i])
	{
			if(str[i] == '=' && str[i - 1] != '+')
				return(1);
			else if(str[i - 1] == '+' && str[i] == '=')
				return(2);
		i++;
	}
	return(3);//if !exists add with null otherwise noth
}

char *first(char *str)
{
	int	i = 0;
	char *p;
	
	p = NULL;
	while(str[i])
		i++;
	p = ft_substr(str, 0, i);
	return(p);
}

int	arg_exist(char *arg)
{
	t_list	*head;

	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(head->key, arg, max(ft_strlen(head->key), ft_strlen(arg))))
			return(0); //  equal
		head = head->next;
	}
	return(1); // not equal
}

void	replace_arg_value(char *second, char *first)

{
	t_list		*head;
	t_arguments	*args;
	
	args = v_lines->command_table->argument;
	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(head->key, first, max(ft_strlen(head->key), ft_strlen(first))))
			head->value = second;
		head = head->next;
	}
}

char	*first_half_for_export_plus(char *str)
{
	int	i = 0;
	char *p;

	p = NULL;
	while(str[i] != '=')
		i++;
	p = ft_substr(str, 0, i - 1);
	return(p);
}

void	replace_second_half_export_plus(char *old_second, char *first_half_var)
{
	t_list *head;
	t_arguments		*args;

	head = v_lines->env_vars_head;
	args = v_lines->command_table->argument;
	while(head)
	{
		if(!ft_strncmp(head->key, first_half_var, max(ft_strlen(head->key), ft_strlen(first_half_var))))
			head->value = old_second;
		head = head->next;
	}
}

char	*old_second_half_export_plus(char *arg)
{
	t_list	*head;
	char	*old_second;

	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(head->key, arg, max(ft_strlen(head->key), ft_strlen(arg))))
			old_second = head->value;
		head = head->next;
	}
	return(old_second);
}
void	ft_export(t_arguments *args)
{
	t_list		*new_arg;
	t_list		*head;
	char		**arr;
	int			env_number;
	int			i = 0;
	int			type;
	int			equal;
	char		*new_second_half;
	char *line;
	char *old_second;
	
	head = v_lines->env_vars_head;
	
	if(!args) //if we have just command
	{
		env_number = env_numb(head);
		arr = sort(head);
		while(i < env_number)
			print_env(arr[i++]);
		free(arr);
	}
	
	while(args)
	{
		type = args_types(args->arg);
		if(type == 0)
			printf("export: '%s': not a valid identifier\n",args->arg);
		else if(type == 3) //without second_half
		{
			equal = arg_exist(first(args->arg));
			if(equal == 1)
			{
				new_arg = ft_lstnew(first(args->arg), NULL);
				ft_lstadd_back(head, new_arg);
			}
		}
		else if(type == 1) //=
		{
			equal = arg_exist(first_half(args->arg));
			if(equal == 1)
			{
				new_arg = ft_lstnew(first_half(args->arg), second_half(args->arg));
				ft_lstadd_back(head, new_arg);
			}
			else if(equal == 0)
				replace_arg_value(second_half(args->arg), first_half(args->arg));
		}
		else if(type == 2) //+=
		{
			equal = arg_exist(first_half_for_export_plus(args->arg));
			if(equal == 1)
			{
				new_arg = ft_lstnew(first_half_for_export_plus(args->arg), second_half(args->arg));
				ft_lstadd_back(head, new_arg);
			}
			else if(equal == 0)
			{
				old_second = old_second_half_export_plus(first_half_for_export_plus(args->arg));
				old_second = ft_strjoin(old_second, second_half(args->arg));
				replace_second_half_export_plus(old_second, first_half_for_export_plus(args->arg));
			}
		}
		args = args->next;
	}
	
}