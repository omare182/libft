#include "libft.h"
size_t len(char const *lenn){
    size_t i;

    i = 0;
    while(lenn[i])
        i++;
    return (i);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    char *new;
    size_t l1;
    size_t l2;
    
    l1 = len(s1);    
    l2 = len(s2);
    new = malloc(l1 + l2 + 1);
    if(!new)
        return (NULL);
    l1 = 0;
    while(s1[l1])
    {
        new[l1] = s1[l1];
        l1++;
    }
    l2 = 0;
    while(s2[l2])
    {
        new[l1 + l2] = s2[l2];
        l2++;
    }
    new[l1 + l2] = '\0';
    return (new);
}

#include <stdio.h>
int main(){
    char s[] = "\0";
    char s2[] = "a   q";
    char *n = ft_strjoin(s,s2);
    size_t i = 0;
    printf("%s \n",n);
       free(n);
}