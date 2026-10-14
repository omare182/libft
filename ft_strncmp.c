#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if(n == 0)
        return (0);
    while(s1[i] && s2[i] && i < n - 1)
    {
        if(s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
   }
    return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}





#include <stdio.h>
#include <string.h>
#include "libft.h"

static int	sign(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

int	main(void)
{
	printf("1.  %d %d\n", sign(ft_strncmp("abc", "abc", 3)), sign(strncmp("abc", "abc", 3)));
	printf("2.  %d %d\n", sign(ft_strncmp("abc", "abd", 3)), sign(strncmp("abc", "abd", 3)));
	printf("3.  %d %d\n", sign(ft_strncmp("abd", "abc", 3)), sign(strncmp("abd", "abc", 3)));
	printf("4.  %d %d\n", sign(ft_strncmp("ab", "abc", 5)), sign(strncmp("ab", "abc", 5)));
	printf("5.  %d %d\n", sign(ft_strncmp("abc", "ab", 5)), sign(strncmp("abc", "ab", 5)));
	printf("6.  %d %d\n", sign(ft_strncmp("", "", 5)), sign(strncmp("", "", 5)));
	printf("7.  %d %d\n", sign(ft_strncmp("", "a", 5)), sign(strncmp("", "a", 5)));
	printf("8.  %d %d\n", sign(ft_strncmp("a", "", 5)), sign(strncmp("a", "", 5)));
	printf("9.  %d %d\n", sign(ft_strncmp("abc", "xyz", 0)), sign(strncmp("abc", "xyz", 0)));
	printf("10. %d %d\n", sign(ft_strncmp("abc", "abd", 2)), sign(strncmp("abc", "abd", 2)));
	printf("11. %d %d\n", sign(ft_strncmp("abc", "abd", 3)), sign(strncmp("abc", "abd", 3)));
	printf("12. %d %d\n", sign(ft_strncmp("abc", "abc", 100)), sign(strncmp("abc", "abc", 100)));
	printf("13. %d %d\n", sign(ft_strncmp("a", "b", 1)), sign(strncmp("a", "b", 1)));
	printf("14. %d %d\n", sign(ft_strncmp("b", "a", 1)), sign(strncmp("b", "a", 1)));
	printf("15. %d %d\n", sign(ft_strncmp("\xff", "a", 1)), sign(strncmp("\xff", "a", 1)));
	printf("16. %d %d\n", sign(ft_strncmp("a", "\xff", 1)), sign(strncmp("a", "\xff", 1)));
	printf("17. %d %d\n", sign(ft_strncmp("abc\0xyz", "abc\0abc", 7)), sign(strncmp("abc\0xyz", "abc\0abc", 7)));
	printf("18. %d %d\n", sign(ft_strncmp("test", "test\0", 10)), sign(strncmp("test", "test\0", 10)));
	printf("19. %d %d\n", sign(ft_strncmp("hello", "help", 4)), sign(strncmp("hello", "help", 4)));
	printf("20. %d %d\n", sign(ft_strncmp("hello", "help", 3)), sign(strncmp("hello", "help", 3)));
	return (0);
}