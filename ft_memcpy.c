#include "libft.h"

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    const unsigned char *s;
    unsigned char *d;
    size_t i;

    i = 0;
    s = (const unsigned char *)src;
    d = (unsigned char *)dst;
    if (!src && !dst)
        return (NULL);
    while(i < n){
        d[i] = s[i];
        i++;
    }
    return (dst);
}