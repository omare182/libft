#include "libft.h"

int count_nb(long n)
{
    int count;

    count = 1;
    if (n < 0)
    {
        count++;
        n = -n;
    }
    while (n > 9)
    {
        count++;
        n /= 10;
    }
    return (count);
}

char *ft_itoa(int n)
{
    long nb;
    char *new;
    int i;

    nb = n;
    i = count_nb(nb);
    new = malloc(sizeof(char) * (i + 1));
    if(!new)
        return (NULL);
    new[i] = '\0';
    i--;
    if(nb < 0)
    {
        new[0] = '-';
        nb = -nb;
        //i--;
    }
    while( i >= 0 && new[i] != '-')
    {
        new[i] = (nb % 10) + '0';
        nb /= 10;
        i--;
    }
    return (new);
} 


// #include <stdio.h>
// int main()
// {
//     char *s = ft_itoa(-2147483648);
//     printf("%s\n",s);
//     char *a = ft_itoa(-0);
//     printf("%s\n",a);
// }
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *ft_itoa(int n);

int main(void)
{
    int tests[] = {
        0,
        -0,
        1,
        -1,
        9,
        -9,
        10,
        -10,
        42,
        -42,
        100,
        -100,
        INT_MAX,
        INT_MIN
    };
    int i = 0;
    char *s;

    while (i < (int)(sizeof(tests) / sizeof(tests[0])))
    {
        s = ft_itoa(tests[i]);
        if (s == NULL)
            printf("Error: malloc failed\n");
        else
        {
            printf("Input: %d | Output: %s\n", tests[i], s);
            free(s);
        }
        i++;
    }
    return (0);
}