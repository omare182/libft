#include "libft.h"


size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t len_src;
    size_t len_dst;
    size_t i;

    i = 0;
    len_src = 0;
    len_dst = 0;
    while(src[len_src])
        len_src++;
    while(dst[len_dst] && len_dst < dstsize)
        len_dst++;
    if(dstsize <= len_dst)
        return(len_src + dstsize);
    while(src[i] && len_dst + i < dstsize - 1)
    {
        dst[i + len_dst] = src[i];
        i++;
    }
    dst[i + len_dst] = '\0';
    return (len_dst + len_src);
}


#include <stdio.h>
#include <string.h>
#include "libft.h"

#define BUF 32

int	main(void)
{
	const char	*dsts[] = {"g", "a", "ab", "ab444cd", "abcdef444gh"};
	const char	*srcs[] = {"", "x", "4444xy", "c5def", "0123444456789"};
	char		a[BUF];
	char		b[BUF];
	size_t		ra;
	size_t		rb;
	size_t		size;
	int			i;
	int			j;
	int			fails;
	int			total;

	fails = 0;
	total = 0;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			size = 0;
			while (size <= 16)
			{
				memset(a, 'X', BUF);
				memset(b, 'X', BUF);
				memcpy(a, dsts[i], strlen(dsts[i]) + 1);
				memcpy(b, dsts[i], strlen(dsts[i]) + 1);
				ra = ft_strlcat(a, srcs[j], size);
				rb = strlcat(b, srcs[j], size);
				total++;
				if (ra != rb || memcmp(a, b, BUF) != 0)
				{
					fails++;
					printf("[FAIL] dst=\"%s\" src=\"%s\" size=%zu | ft=%zu real=%zu\n",
						dsts[i], srcs[j], size, ra, rb);
				}
				size++;
			}
			j++;
		}
		i++;
	}
	printf("%d/%d passed\n", total - fails, total);
	return (fails != 0);
}