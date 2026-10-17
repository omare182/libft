#include "libft.h"
char *ft_strjoin(char const *s1, char const *s2)
{
    char *new;
    size_t i;
    size_t l1 = 0;
    size_t l2 = 0;
    
    l1 = ft_strlen(s1);    
    l2 = ft_strlen(s2);
    i = 0;
    new = malloc(l1 + l2 + 1);
    if(!new)
        return (NULL);
    while(s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    l2 = 0;
    while(s2[l2]){
        new[i + l2] = s2[l2];
        l2++;
    }
    new[i + l2] = '\0';
    return (new);
}

#include <stdio.h>
int main(){
    char s[] = "";
    char s2[] = "";
    char *n = ft_strjoin(s,s2);
    size_t i = 0;
    printf("%s \n",n);
    free(n);
}