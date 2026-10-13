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
    while(str[i]){
        if(str[i] == '-')
        {
            sign *= -1;
            coun++;
        }
        if(coun == 2)
            return (0);
        if(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
            i++;
        if(str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
        }
        i++;
    }
    return (res * sign);
}

