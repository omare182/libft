#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *str1;
    unsigned char *str2;
    size_t i;

    i = 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    if(n == 0)
        return (0);
    while(i < n - 1)
    {
        if(str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++; 
    }
    return (str1[i] - str2[i]);
}




#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char    s1[] = "atoms\0abc";
    char    s2[] = "atoms\0zxy";
    char    hi1[] = "ab\xff" "cd";
    char    hi2[] = "ab\x00" "cd";

    printf("1.  ft: %d | std: %d\n", ft_memcmp("salut", "salut", 5), memcmp("salut", "salut", 5));
    printf("2.  ft: %d | std: %d\n", ft_memcmp("t\0est", "t\0est", 5), memcmp("t\0est", "t\0est", 5));
    printf("3.  ft: %d | std: %d\n", ft_memcmp("test", "tess", 4), memcmp("test", "tess", 4));
    printf("4.  ft: %d | std: %d\n", ft_memcmp("same", "same", 0), memcmp("same", "same", 0));
    printf("5.  ft: %d | std: %d\n", ft_memcmp("abc", "abcdef", 3), memcmp("abc", "abcdef", 3));
    printf("6.  ft: %d | std: %d\n", ft_memcmp("abcdef", "abc", 3), memcmp("abcdef", "abc", 3));
    printf("7.  ft: %d | std: %d\n", ft_memcmp("abcdef", "abc", 4), memcmp("abcdef", "abc", 4));
    printf("8.  ft: %d | std: %d\n", ft_memcmp(s1, s2, 5), memcmp(s1, s2, 5));
    printf("9.  ft: %d | std: %d\n", ft_memcmp(s1, s2, 7), memcmp(s1, s2, 7));
    printf("10. ft: %d | std: %d\n", ft_memcmp("zyxbcba", "zyxabca", 7), memcmp("zyxbcba", "zyxabca", 7));
    printf("11. ft: %d | std: %d\n", ft_memcmp(hi1, hi2, 5), memcmp(hi1, hi2, 5));
    printf("12. ft: %d | std: %d\n", ft_memcmp("\x20\x80", "\x20\x00", 2), memcmp("\x20\x80", "\x20\x00", 2));
    printf("13. ft: %d | std: %d\n", ft_memcmp("testSS", "test", 5), memcmp("testSS", "test", 5));
    printf("14. ft: %d | std: %d\n", ft_memcmp("test", "testSS", 5), memcmp("test", "testSS", 5));
    printf("15. ft: %d | std: %d\n", ft_memcmp("", "", 0), memcmp("", "", 0));
    printf("16. ft: %d | std: %d\n", ft_memcmp("", "a", 1), memcmp("", "a", 1));

    return (0);
}