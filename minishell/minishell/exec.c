#include "minishell.h"
#include "execution.h"

int ft_lstsize(t_arguments *lst)
{
	int i;
	t_arguments *itering;

	itering = lst;
	i = 0;
	while (itering)
	{
		itering = itering->next;
		i++;
	}
	return (i);
}

char **args_to_table(t_arguments *args)
{
	char **args_array;
	int size;
	int i;

	size = ft_lstsize(args);
	args_array = malloc(sizeof(char *) * (size + 1));
	args_array[size] = 0;
	i = 0;
	while (i < size)
	{
		args_array[i] = args->arg;
		args = args->next;
		i++;
	}
	return(args_array);
}

int number_of_commands(t_commandtable *command_table)
{
	int i;
	
	i = 0;
	while(command_table)
	{
		i++;
		command_table = command_table->next;
	}
	return i;
}

int	commande_with_path(t_commandtable *commande)
{
	
	char *back_slash;
	int i = 0;
	int j = 1;
	int can_access;
	t_arguments *args;
	char	**a;

	args = v_lines->command_table->argument;
	back_slash = ft_strchr(commande->command, '/');
	if(back_slash == NULL)
		return(0) ;
	else
		can_access = access(back_slash, X_OK);
	if(can_access == 0)
	{
		a = malloc((ft_lstsize(args) + 2) * sizeof(char *));
		if(args)
		{
			while(a[j] && args)
			{
				a[0] =  back_slash;
				a[j] =  args->arg;
				j++;
				args = args->next;
			}
			a[j] = NULL;

		}
		else
		{
			a[0] = back_slash;
			a[1] = NULL;
		}
		if((execve(back_slash,a, NULL)) == -1)
		{
			perror("execve");
			exit(0);
		}
		free(a);
	}
	if(can_access == -1)
	{
		printf("bash tsetta: %s: No such file or directory\n", commande->command);
		exit(127);
	}
	while(back_slash[i])
		i++;
	if(back_slash[i - 1] == '/')
	{
		printf("bash tsetta: %s: Not a directory\n", back_slash);
		exit(126);
	}
	
	return(can_access);
}

char	**parsing_path(char *commande)
{
	char **arr;
	char *path;
	t_list	*head;
	int 	i;
	int flag;

	head = v_lines->env_vars_head;
	while(head)
	{
		if(!ft_strncmp(head->key, "PATH", max(ft_strlen(head->key), ft_strlen("PATH"))))
			path = head->value;
		head = head->next;
	}
	arr = ft_split(path, ':');
	i = 0;
	while(arr[i])
	{
		arr[i] = ft_strjoin(arr[i], "/");
		i++;
	}
	i = 0;
	while(arr[i])
	{
		arr[i] = ft_strjoin(arr[i], commande);
		i++;
	}
	return(arr);
}

void correct_access(t_commandtable *command_table)
{
	char		**path;
	int			flag;
	int			j = 1;
	t_arguments *args;
	int			i;
	char		**a;
	int			built_in_number;

	args = command_table->argument;
	built_in_number = is_built_in(v_lines);
	i = 0;
	a = malloc((ft_lstsize(args) + 2) * sizeof(char *));
	path = parsing_path(command_table->command);
	while(path[i])
	{
		flag = access(path[i], X_OK);
		if(flag == 0 && !built_in_number)
		{
			if(args)
			{
				while(a[j] && args)
				{
					a[0] =  path[i];
					a[j] =  args->arg;
					args = args->next;
					j++;
				}
				a[j] = NULL;
			}
			else
			{
				a[0] = path[i];
				a[1] = NULL;
			}
			if((execve(path[i], a, NULL)) == -1)
			{
				perror("execve");
				exit(0);
			}
			free(a);
		}
		i++;
	}
}

int execute(t_line_processing_history *v_lines)
{
	t_commandtable *command_table;
	char **args;
	int fd[2];
	int pipe_save;
	int out;

	int can_access;

	pipe_save = 0;
	command_table = v_lines->command_table;
	v_lines->commands_number = number_of_commands(command_table);
	v_lines->process_id = malloc(sizeof(int) * v_lines->commands_number);
	while (command_table != 0)
	{
		pipe(fd);
		out = fd[1];
		v_lines->process_id[v_lines->iterator++] = fork();
		if (v_lines->process_id[v_lines->iterator - 1] == 0)
		{
			close(fd[0]);
			if (pipe_save != 0)
				dup2(pipe_save, 0);
			if(command_table -> input_fd)
				dup2(command_table->input_fd, 0);
			if (command_table -> output_fd >= 3)
			{
				out = command_table -> output_fd;
			}
			else if (command_table ->next == 0)
				out = 1;
			dup2(out, 1);
			//command//command_table->command;
			args = args_to_table(command_table->argument);
			// complet

			//> is built in >> exec built in
			//else check access and exec _ if wrong access print command not found
			can_access = commande_with_path(v_lines->command_table);
			correct_access(command_table);

			// check access and execute built in or excve if its not in them
			// for excve args is argument table
			// v_lines->env_vars is env vars table
			// v_lines->exit_status is where to put exit status from waitpid
			return 1;
		}
		
		if (pipe_save != 0 && pipe_save != 1)
			close(pipe_save);

		close(fd[1]);
		pipe_save = fd[0];
		command_table = command_table->next;
	}
	//wait all childreen while none fails
	//children ids are saved in command table process id and number of commands(children) are stored in command_table->commands_number
	return 1;
}
