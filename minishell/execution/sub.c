#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;

	i = 0;
	if (!src)
		return (0);
	//if (!*src || len == 0 || ft_strlen((char *) src) <= start)
		//return (ft_strdup(""));
	if (len > strlen((char *)src))
		len = strlen((char *)src) - start;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (0);
	while (src[i + start] && i < len)
	{
		dest[i] = src[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main()
{
	char *d="ma+/=lika";
	int j=0;
	char	*p;
	while(d[j])
	{
		if(d[j] == '=')
			p = ft_substr(d, j+1,strlen(d));
		j++;
	}
	printf ("%s\n%lu\n", p, strlen (p));

}