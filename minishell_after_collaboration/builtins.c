/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:35:27 by maamer            #+#    #+#             */
/*   Updated: 2022/09/20 17:42:10 by maamer           ###   ########.fr       */
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
		printf("%s=",head->key);
		printf("%s",head->value);
		printf("\n");
		head = head->next;	
	}
}

void	ft_cd()
{
	t_arguments *args = v_lines->command_table->argument;
	int i = 0;
	//printf("cd is here\n");
	if (args == NULL)
	{
		if(chdir(getenv("HOME")) == -1)
		perror("chdir");
	}
	else if (args->arg[i] == '~')
		chdir(getenv("HOME"));
	else if (chdir(args->arg) == -1 && (args->arg[i] != '~'))
		printf("cd :%s: No such file or directory\n", args->arg);
}
