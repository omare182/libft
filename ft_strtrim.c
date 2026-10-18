#include "libft.h"
size_t len(char const *lenn){
    size_t i;

    i = 0;
    while(lenn[i])
        i++;
    return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t n;
    size_t i;
    size_t j;
    char *new;
    
    j = 0;
    i = 0;
    n = 0;
    new = malloc((len(s1) - len(set)) + 1);
    if(!new)
        return (NULL);
    while(s1[i])
    {
        if(s1[i] != set[j])
        {
            new[n] == s1[i];
            n++;
            i++;
        }
        else if(len(s1) - i == len(set) - j)
        {
            while(s1[i] == set[j])
            {
                i++;
                j++;
            }
        }
        i++;
    }
    return (new);
}

#include <stdio.h>
int main(){
    char const s[] = "omar kasmi";
    char const set[] = "omkas";
        char *new = ft_strtrim(s,set);

    printf("%s",new);
    free(new);
}