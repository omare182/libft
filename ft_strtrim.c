#include "libft.h"
int is_set(char c, char const *set)
{
    int i;

    i = 0;
    while(set[i])
    {
        if(set[i] == c)
            return (1);
        i++;
    }
    return (0);
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t end;
    size_t i;
    size_t start;
    char *new;
    
    j = 0;
    i = 0;
    n = 0;
    new = malloc((ft_strlen(s1) - ft_strlen(set)) + 1);
    if(!new)
        return (NULL);
    while(s1[i] && is_set(s1[i],set) == 1)
        i++;
    start = i;
    end = ft_strlen(s1);
    while(end > start && is_set(s1[end],set) == 1)
        end--;
    i = 0;
    while(start < end)
    {
        new[i] = s1[start];
        start++;
        i++;
    }
    return (new);
}

// #include <stdio.h>
// int main(){
//     char const s[] = "omar kasmi";
//     char const set[] = "omkas";
//         char *new = ft_strtrim(s,set);

//     printf("%s",new);
//     free(new);
// =======
// #include "libft.h"


// int is_set(char s, char const *set)
// {
//     size_t i;

//     i = 0;
//     while(set[i])
//     {
//         if(set[i] == s)
//             return (1);
//         i++;
//     }
//     return (0);
// }
// void coppy(char s, char *new, size_t i)
// {
//         new[i] = s;
//         i++;
// }
// char *ft_strtrim(char const *s1, char const *set)
// {
//     char *new;
//     int count;
//     size_t i;
//     size_t j;

//     j = 0;
//     i = 0;
//     count = 0;
//     new = malloc((ft_strlen(s1) - ft_strlen(set)) + 1);
//     if(!new)
//         return (NULL);
//     while(s1[i])
//     {
//         if(is_set(s1[i], set) == 0)
//             coppy(s1[i],new,j);
        
//     }
//     return (new);
// }

// #include <stdio.h>
// int main(){
//     char const s[] = "omar";
//     char const set[] = "o";
//     char *new = ft_strtrim(s,set);

//     printf("%s",new);
//     free(new);
// >>>>>>> linux
// }