#include "libft.h"

int ft_tolower(int c)
{
    if(c <= 'a' && c >= 'z')
        c += 32;
    return (c);
}
#include <stdio.h>
int main(){
    int i = ft_toupper(65);
    printf("%d",i);
}
