#include "libft.h"

int ft_isprint(int c)
{
    if((c <= '~' && c >= '!') || c == ' ')
        return (1);
    return (0);
}