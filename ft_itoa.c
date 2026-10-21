#include "libft.h"

int count_nb(long n)
{
    int count;

    count = 0;
    if (n <= 0)
    {
        count++;
        n = -n;
    }
    while (n > 0)
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
    new = malloc(count_nb(nb) + 1);
    if(!new)
        return (NULL);
    if(nb < 0)
    {
        new[0] = '-';
        nb = -nb;
    }
    new[i] = '\0';
    while(i >= 0 && new[i] != '-')
    {
        new[i] = (nb % 10) + '0';
        nb /= 10;
        i--;
    }
    return (new);
}


#include <stdio.h>
int main()
{
   char *s = ft_itoa(-1337);
    printf("%s\n",s);


}
