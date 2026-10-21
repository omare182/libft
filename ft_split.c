#include <libft.h>
int ft_end(char const *s, char c)
{
    int i;

    i = 0;
    while(s[i] != c)
        i++;
    return (i);
}
int ft_cp(char const *s, int start, int end,char *new)
{
    int i;

    i = 0;
    while(start < end)
        new[i++] = s[start++];
    return (i);
}

char **ft_split(char const *s, char c)
{
    char **new;

    new = malloc(ft_strlen(s) * sizeof(char *));
    if(!new)
        return (NULL);
    




    return (new);
}








int countsep(char *s, char sep)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(s[i])
    {
        if(s[i] == sep)
            count++;
        i++;
    }
    return (i);
}