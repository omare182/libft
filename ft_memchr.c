#include "libft.h"

void *ft_memchr(const void *s , int c, size_t n)
{
    unsigned char *str;
    size_t i;
    
    i = 0;
    str =  (unsigned char *)s;
    while (i < n)
    {
        if(((unsigned char *)str)[i] == (unsigned char)c)
            return ((void *) &str[i]);
        i++;
    }
    return (NULL);
}



#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char	buf[] = "abc\0def";
	char	hi[] = "ab\xff" "cd";

	printf("1.  %p %p\n", ft_memchr("hello world", 'w', -1), memchr("hello world", 'w', -1));
	printf("2.  %p %p\n", ft_memchr("hello world", 'h', 11), memchr("hello world", 'h', 11));
	printf("3.  %p %p\n", ft_memchr("hello world", 'd', 11), memchr("hello world", 'd', 11));
	printf("4.  %p %p\n", ft_memchr("hello world", 'l', 11), memchr("hello world", 'l', 11));
	printf("5.  %p %p\n", ft_memchr("hello world", 'z', 11), memchr("hello world", 'z', 11));
	printf("6.  %p %p\n", ft_memchr("hello world", 'w', 6), memchr("hello world", 'w', 6));
	printf("7.  %p %p\n", ft_memchr("hello world", 'w', 7), memchr("hello world", 'w', 7));
	printf("8.  %p %p\n", ft_memchr("hello world", 'h', 0), memchr("hello world", 'h', 0));
	printf("9.  %p %p\n", ft_memchr("hello", '\0', 5), memchr("hello", '\0', 5));
	printf("10. %p %p\n", ft_memchr("hello", '\0', 6), memchr("hello", '\0', 6));
	printf("11. %p %p\n", ft_memchr(buf, 'd', 7), memchr(buf, 'd', 7));
	printf("12. %p %p\n", ft_memchr(buf, '\0', 7), memchr(buf, '\0', 7));
	printf("13. %p %p\n", ft_memchr(buf, 'd', 3), memchr(buf, 'd', 3));
	printf("14. %p %p\n", ft_memchr(hi, 255, 5), memchr(hi, 255, 5));
	printf("15. %p %p\n", ft_memchr(hi, -1, 5), memchr(hi, -1, 5));
	printf("16. %p %p\n", ft_memchr("abc", 'a' + 256, 3), memchr("abc", 'a' + 256, 3));
	printf("17. %p %p\n", ft_memchr("aaaa", 'a', 4), memchr("aaaa", 'a', 4));
	printf("18. %p %p\n", ft_memchr("", 'a', 0), memchr("", 'a', 0));
	return (0);
}