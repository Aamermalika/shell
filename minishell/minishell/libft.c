/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maamer <maamer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:11:19 by maamer            #+#    #+#             */
/*   Updated: 2022/09/26 19:00:34 by maamer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	i;
	int		dlen;
	int		slen;

	i = 0;
	s = (char *)src;
	dlen = ft_strlen(dst);
	slen = ft_strlen(s);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = s[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (slen);
}

int	count_string2(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (str[i - 1] == c && str[i] != c))
			count++;
		i++;
	}
	return (count);
}

int	string_size1(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	**t(char **arr, char c, const char *s)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		len = string_size1(s + i, c);
		if (s[i])
		{
			arr[j] = malloc ((len + 1) * sizeof(char));
			ft_strlcpy (arr[j], s + i, len + 1);
				j++;
		}
		i = len + i;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char  *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = malloc(sizeof(char *) * (count_string2(s, c) + 1));
	if (!arr)
		return (0);
	return (t(arr, c, s));
}


int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}