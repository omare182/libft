#include "libft.h"

char *ft_strdup(const char *s)
{
    char *new;
    int i;

    i = 0;
    while(s[i])
        i++;
    new = malloc((sizeof(char) * i) + 1);
    if(!new)
        return (NULL);
    i = 0;
    while(s[i])
    {
        new[i] = s[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}
