/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:50:54 by maamer            #+#    #+#             */
/*   Updated: 2022/09/25 17:27:24 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// void	sort_env(char **env)
// {
// 	int i = 0;
// 	char *str;
// 	while(env[i])
// 	{
// 		if(env[i] > env[i + 1])
// 			str = env[i + 1];
// 		i++;
// 	}
// }

// int main()
// {
// 	char *s = "aa"
// }



// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	unsigned char	*part1;
// 	unsigned char	*part2;
// 	size_t			i;

// 	i = 0;
// 	part1 = (unsigned char *)s1;
// 	part2 = (unsigned char *)s2;
// 	while (i < n)
// 	{
// 		if (part1[i] != part2[i])
// 			return (part1[i] - part2[i]);
// 		i++;
// 	}
// 	return (0);
// }
#include "minishell.h"

// int max(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

// int is_higher(char *str1, char *str2)
// {
// 	if(ft_strncmp(str1, str2, max(ft_strlen(str1),ft_strlen(str2))) > 0)
// 		return 1;
// 	return 0;
// }
// int main()
// {
//     printf("%d",is_higher("abc", "ab"));
// }

// void	ft_swap(char **a, char **b)
// {
// 	char	*c;
// 	c = *a;
// 	*a = *b;
// 	*b = c;
// }

// int main()
// {
// 	char *a = "malika";
// 	char *b= "aamer";
// 	ft_swap(&a , &b);
// 	printf("a----->%s  b----->%s\n",a,b);
// }

#include <stdio.h>
#include <string.h>
int main()
{
  char name[25][50],temp[25];
  int n,i,j;
  
       printf("\n\nSorts the strings of an array using bubble sort :\n");
       printf("-----------------------------------------------------\n");
  
 
  	printf("Input number of strings :");
  	scanf("%d",&n);

	printf("Input string %d :\n",n);
  for(i=0;i<=n;i++)
  {
       
       fgets(name[i], sizeof name, stdin);
  }
     /*Logic Bubble Sort*/

     for(i=1;i<=n;i++)
	for(j=0;j<=n-i;j++)
	  if(strcmp(name[j],name[j+1])>0)
	  { 
            strcpy(temp,name[j]);
	    	strcpy(name[j],name[j+1]);
	    	strcpy(name[j+1],temp);
	  }
   printf("The strings appears after sorting :\n");
	      for(i=0;i<=n;i++)
		 printf("%s\n",name[i]);
 
} 