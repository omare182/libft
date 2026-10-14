#include "libft.h"

void *ft_memset(void *p, int c, size_t len)
{
    unsigned char *d;
    unsigned char x;
    size_t i;

    i = 0;
    x = c;
    d = (unsigned char *)p;
    while(i < len)
        d[i++] = x;
    return (p);
}
