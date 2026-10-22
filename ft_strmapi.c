#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char c))
{
    int i;
    char *new;

    i = 0;
    if (!s || !f)
        return (NULL);
    new = ft_strdup(s);
    if(!new)
        return (NULL);
    while(new[i])
    {
        new[i] = f(i,s[i]);
        i++;
    }
    return (new);
}

// #include <stdio.h>
// #include <stdlib.h>

// char	ft_upper(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*new;

// 	str = "abcd";
// 	new = ft_strmapi(str, ft_upper);
// 	if (!new)
// 		return (1);
// 	printf("Original: %s\n", str);
// 	printf("New: %s\n", new);
// 	free(new);
// 	return (0);
// }