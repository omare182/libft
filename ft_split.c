#include "libft.h"
#include <stdio.h>
int ft_end(char const *s,int start)
{
    while(s[start] !=  ' ')
        start++;
    return (start);
}
int ft_cp(char const *s, int start, int end,char *new,char c)
{
    int i;

    i = 0;
    while(start < end)
    {
        new[i] = s[start];
    }
    new[i] = '\0';
    return (end);
}
int countsep(char *s)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(s[i])
    {
        if(s[i] == ' ')
            count++;
        i++;
    }
    return (i);
}
char **ft_split(char const *s, char c)
{
    char **new;
    int start;
    int i;

    i = 0;
    start = 0;
    int end;
    new = malloc(countsep(s) + (countsep(s) - 1));
    if(!new)
        return (NULL);
    while(s[i])
    {    

        if(s[i] == ' ')
        {
            i = ft_cp(s,start,ft_end(s,start),*new,c);  
            start = i + 1;
        }
        i++;
    }
    return (new);
}

int main()
{
    char s[] = "kami oma";
    char **new = ft_split(s,'&'); 
    int i = 0;
    int j = 0;
    while(new[i][j])
    {
        j = 0;
        while(new[i][j])
        {
            write(1, &new[i][j], 1);
            j++;
        }
        i++;
    }

}





