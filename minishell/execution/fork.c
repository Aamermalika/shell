#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
//#include <direct.h>

// int main()
// {
// 	char buff[256];
// 	if(getcwd(buff, sizeof(buff)) == NULL)
// 	{
// 		perror("getcwd");
// 		return(1);
// 	}
// 	printf("current working diretory : %s\n",buff);
// }



// int	main(int ac, char **av, char **env)
// {
// 	int a = fork();
// 	if (!a)
// 		execve(av[1], av + 1, env);
// 	usleep(100000);
// 	if (chdir("54") == -1)
// 	{
// 		perror("cd");
// 		exit (1);
// 	}
// 	printf ("\n\n-----------------------\n\n");
// 	int b = fork();
// 	if (!b)
// 		execve(av[1], av + 1, env);
// }

// int main()
// {
//     int id;
//     id = fork();
//     if(id != 0)
//     {
//         fork();
//     }
//         printf("%d\n",id);
// }


// int main()
// {
// 	int fd[2];
// 	int id;
// 	if(pipe(fd) == -1)
// 	{
// 		printf("error\n");
// 		return(1);
// 	}
// 	id = fork();
// 	if(id == 0)
// 	{
		
// 	}
// }


