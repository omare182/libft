#include <stdio.h>

int ft_atoi(char *str)
{
    int i;
    int res;
    int sign;
    int coun;
    i = 0;
    res = 0;
    sign = 1;
    coun = 0;
    while(str[i] == ' ' || (str[i] >=9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    
    return (res * sign);
}

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    printf("1.  ft: %d | std: %d\n", ft_atoi("12341473823232323232323232642374"), atoi("12332482323232323264827644"));
    printf("2.  ft: %d | std: %d\n", ft_atoi("   -42"), atoi("   -42"));
    printf("3.  ft: %d | std: %d\n", ft_atoi("   +567"), atoi("   +567"));
    printf("4.  ft: %d | std: %d\n", ft_atoi("\t\n\r\v\f 99"), atoi("\t\n\r\v\f 99"));
    printf("5.  ft: %d | std: %d\n", ft_atoi("123abc456"), atoi("123abc456"));
    printf("6.  ft: %d | std: %d\n", ft_atoi("abc123"), atoi("abc123"));
    printf("7.  ft: %d | std: %d\n", ft_atoi("++123"), atoi("++123"));
    printf("8.  ft: %d | std: %d\n", ft_atoi("--123"), atoi("--123"));
    printf("9.  ft: %d | std: %d\n", ft_atoi("-+123"), atoi("-+123"));
    printf("10. ft: %d | std: %d\n", ft_atoi("2147483647"), atoi("2147483647"));
    printf("11. ft: %d | std: %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
    printf("12. ft: %d | std: %d\n", ft_atoi("0"), atoi("0"));
    printf("13. ft: %d | std: %d\n", ft_atoi("  +000123"), atoi("  +000123"));
    printf("14. ft: %d | std: %d\n", ft_atoi(""), atoi(""));

    return (0);
}
