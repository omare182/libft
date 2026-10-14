#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i])
    {
        
        if(s[i] == (char)c)
            return ((char *)s + i);
        i++;
    }
    if((char)c == '\0')
        return ((char *)s + i);
    return (NULL);
}
#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("1. %p %p\n", (void *)ft_strchr("hello world", 'w'), (void *)strchr("hello world", 'w'));
	printf("2. %p %p\n", (void *)ft_strchr("hello world", 'h'), (void *)strchr("hello world", 'h'));
	printf("3. %p %p\n", (void *)ft_strchr("hello world", 'd'), (void *)strchr("hello world", 'd'));
	printf("4. %p %p\n", (void *)ft_strchr("hello world", 'o'), (void *)strchr("hello world", 'o'));
	printf("5. %p %p\n", (void *)ft_strchr("hello world", 'z'), (void *)strchr("hello world", 'z'));
	printf("6. %p %p\n", (void *)ft_strchr("hello world", '\0'), (void *)strchr("hello world", '\0'));
	printf("7. %p %p\n", (void *)ft_strchr("", 'a'), (void *)strchr("", 'a'));
	printf("8. %p %p\n", (void *)ft_strchr("", '\0'), (void *)strchr("", '\0'));
	printf("9. %p %p\n", (void *)ft_strchr("aaaa", 'a'), (void *)strchr("aaaa", 'a'));
	printf("10. %p %p\n", (void *)ft_strchr("abcabc", 'c'), (void *)strchr("abcabc", 'c'));
	printf("11. %p %p\n", (void *)ft_strchr("abc", 'A'), (void *)strchr("abc", 'A'));
	printf("12. %p %p\n", (void *)ft_strchr("abc", 'a' + 256), (void *)strchr("abc", 'a' + 256));
	printf("13. %p %p\n", (void *)ft_strchr("abc", '\0' + 256), (void *)strchr("abc", '\0' + 256));
	printf("14. %p %p\n", (void *)ft_strchr("abc", -1), (void *)strchr("abc", -1));
	printf("15. %p %p\n", (void *)ft_strchr("abc\xff", 255), (void *)strchr("abc\xff", 255));
	printf("16. %p %p\n", (void *)ft_strchr("a b", ' '), (void *)strchr("a b", ' '));
	return (0);
}