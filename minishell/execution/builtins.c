/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:35:27 by maamer            #+#    #+#             */
/*   Updated: 2022/09/16 19:00:22 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	exec()
{
	int id;
	char  *a[] = { "/bin/ls","-la", NULL};
	id = fork();
	if(!id)
	{
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

void	ft_env(char **envp)
{
	char **str;
	char *copy;

	//strdup()
	str = envp;
	while(*str)
	{
		copy = *str;
		printf("%s\n", copy);
		str++;
	}
}

void	ft_cd(char **split)
{
	int i = 0;
	if (split[1] == NULL)
	{
		if(chdir(getenv("HOME")) == -1)
		perror("chdir");
	}
	else if (split[1][i] == '~')
		chdir(getenv("HOME"));
	else if (chdir(split[1]) == -1 && (split[1][i] != '~'))
		printf("cd :%s: No such file or directory\n", split[1]);
}

// void	ft_export(char **env)
// {
// 	t_list	*lst = NULL;
// 	t_list *tmp;
// 	int		i = 0;
// 	tmp = lst;
// 	while(lst)
// 	{
// 		printf("%s",lst->key = env[i]);
// 		lst = lst->next;
// 		i++;
// 	}
// 	lst = tmp;
	
	
	
	
// }