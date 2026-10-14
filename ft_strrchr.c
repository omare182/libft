#include "libft.h"

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    if((char)c == '\0')
        return ((char *)s + i);
    while(i > 0)
    {
        i--;
        if(s[i] == (char)c)
            return ((char *)s + i);
    }
    return (NULL);
}


#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("1. %p %p\n", (void *)ft_strrchr("hello world", 'o'), (void *)strrchr("hello world", 'o'));
	printf("2. %p %p\n", (void *)ft_strrchr("hello world", 'h'), (void *)strrchr("hello world", 'h'));
	printf("3. %p %p\n", (void *)ft_strrchr("hello world", 'd'), (void *)strrchr("hello world", 'd'));
	printf("4. %p %p\n", (void *)ft_strrchr("hello world", 'l'), (void *)strrchr("hello world", 'l'));
	printf("5. %p %p\n", (void *)ft_strrchr("hello world", 'z'), (void *)strrchr("hello world", 'z'));
	printf("6. %p %p\n", (void *)ft_strrchr("hello world", '\0'), (void *)strrchr("hello world", '\0'));
	printf("7. %p %p\n", (void *)ft_strrchr("", 'a'), (void *)strrchr("", 'a'));
	printf("8. %p %p\n", (void *)ft_strrchr("", '\0'), (void *)strrchr("", '\0'));
	printf("9. %p %p\n", (void *)ft_strrchr("aaaa", 'a'), (void *)strrchr("aaaa", 'a'));
	printf("10. %p %p\n", (void *)ft_strrchr("abcabc", 'a'), (void *)strrchr("abcabc", 'a'));
	printf("11. %p %p\n", (void *)ft_strrchr("abcabc", 'b'), (void *)strrchr("abcabc", 'b'));
	printf("12. %p %p\n", (void *)ft_strrchr("abcabc", 'c'), (void *)strrchr("abcabc", 'c'));
    }