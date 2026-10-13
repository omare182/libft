#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{

    size_t len_src;
    size_t i;

    len_src = 0;
    i = 0;

    
    while(src[len_src])
        len_src++;
    if(dstsize == 0)
        return (len_src);
    while(i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    
    dst[i] = '\0';
    return (len_src);
}