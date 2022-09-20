/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:35:43 by maamer            #+#    #+#             */
/*   Updated: 2022/09/20 10:42:50 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "execution.h"
// #include "./minishell.h" 

// char	**duplicate_envirement_vars(char **env)
// {
// 	int		env_vars_count;
// 	char	**array;
// 	int		i;

// 	i = 0;
// 	env_vars_count = 0;
// 	while (env[env_vars_count])
// 		env_vars_count++;
// 	array = malloc(sizeof(char *) * (env_vars_count + 1));
// 	while (i < env_vars_count)
// 	{
// 		array[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	array[i] = 0;
// 	return array;
// }
// char *first_half(char *str)
// {
// 	int	i = 0;
// 	char *p;
// 	while(str[i] != '=')
// 		i++;
// 	p = ft_substr(str, 0, i);
// 	printf("%s\n",p);
// 	return(p);
// }

// char *second_half(char *str)
// {
// 	int		i;
// 	char	*p;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if(str[i] == '=')
// 			p = ft_substr(str, i+1, ft_strlen(str));
// 		i++;
// 	}
// 	return(p);
// }

// t_list *env_vars_list(char **env)
// {
// 	t_list	*lst;
// 	t_list *tmp = NULL;
// 	int		i = 1;
// 	int env_vars_count;
// 	t_list *new_node;

// 	env_vars_count = 0;
// 	while (env[env_vars_count])
// 		env_vars_count++;
// 	if (env_vars_count)
// 	{
// 		lst = ft_lstnew(first_half(env[0]), second_half(env[0]));
// 		tmp = lst;
// 		while(i < env_vars_count)
// 		{
// 			new_node = ft_lstnew(first_half(env[i]), second_half(env[i]));
// 			ft_lstadd_back(lst, new_node);
// 			lst = lst->next;
// 			i++;
// 		}
// 	}
// 	lst = tmp;
// 	return (tmp);
// }
// int main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	char	**env_duplicate_array;
// 	t_list	*env_vars_head;
// 	char *first;


// 	env_duplicate_array = duplicate_envirement_vars(env);
// 	env_vars_head = env_vars_list(env_duplicate_array);
// 	//first = first_half(env_duplicate_array[1]);
// 	t_list *iter = env_vars_head;
// 	while(iter)
// 	{

// 		printf("%s \n", iter->value);
// 		iter = iter->next;
// 	}
// }
