#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    i = 0;
    if(needle[i] == '\0')
        return ((char *)&haystack[i]);
    while(i < len && haystack[i])
    {
        j = 0;
        while(i + j < len && haystack[i + j] == needle[j])
            j++;   
         if(needle[j] == '\0')
                return ((char *)&haystack[i]);
        i++;
    }
    return (NULL);
}


// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
//     const char *haystack = "Foo Bar Baz Bug";
//     const char *empty = "";

//     printf("1.  ft: %s | std: %s\n", ft_strnstr(haystack, "Bar", 8), strnstr(haystack, "Bar", 8));
//     printf("2.  ft: %s | std: %s\n", ft_strnstr(haystack, "Bar", 6), strnstr(haystack, "Bar", 6));
//     printf("3.  ft: %s | std: %s\n", ft_strnstr(haystack, "Bar", 7), strnstr(haystack, "Bar", 7));
//     printf("4.  ft: %s | std: %s\n", ft_strnstr(haystack, "Baz", 11), strnstr(haystack, "Baz", 11));
//     printf("5.  ft: %s | std: %s\n", ft_strnstr(haystack, "Baz", 10), strnstr(haystack, "Baz", 10));
//     printf("6.  ft: %s | std: %s\n", ft_strnstr(haystack, "", 6), strnstr(haystack, "", 6));
//     printf("7.  ft: %s | std: %s\n", ft_strnstr(haystack, "", 0), strnstr(haystack, "", 0));
//     printf("8.  ft: %s | std: %s\n", ft_strnstr(haystack, "Foo", 0), strnstr(haystack, "Foo", 0));
//     printf("9.  ft: %s | std: %s\n", ft_strnstr(haystack, "Foo", 3), strnstr(haystack, "Foo", 3));
//     printf("10. ft: %s | std: %s\n", ft_strnstr(haystack, "NotFound", 15), strnstr(haystack, "NotFound", 15));
//     printf("11. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15), strnstr("lorem ipsum dolor sit amet", "lorem", 15));
//     printf("12. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15), strnstr("lorem ipsum dolor sit amet", "ipsum", 15));
//     printf("13. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15), strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//     printf("14. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "sit", 10), strnstr("lorem ipsum dolor sit amet", "sit", 10));
//     printf("15. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "sit", 20), strnstr("lorem ipsum dolor sit amet", "sit", 20));
//     printf("16. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30), strnstr("lorem ipsum dolor sit amet", "consectetur", 30));
//     printf("17. ft: %s | std: %s\n", ft_strnstr("lorem ipsum dolor sit amet", "sit", 0), strnstr("lorem ipsum dolor sit amet", "sit", 0));
//     printf("18. ft: %s | std: %s\n", ft_strnstr(NULL, "wor", 0), strnstr(NULL, "wor", 0));
//     printf("19. ft: %s | std: %s\n", ft_strnstr("a\0bc", "bc", 4), strnstr("a\0bc", "bc", 4));
//     printf("20. ft: %s | std: %s\n", ft_strnstr(empty, "", 1), strnstr(empty, "", 1));

//     return (0);
// }