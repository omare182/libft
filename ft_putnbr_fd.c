#include "libft.h"
void ft_putnbr_fd(int n, int fd)
{
    long nb;

    nb = n;
    if(nb < 0)
    {
        write(fd, "-", 1);
        nb = -nb;
    }
    if(nb > 9)
    {
        ft_putnbr_fd(nb / 10, fd);
    }    
    ft_putchar_fd((nb % 10) + '0', 1);
}
int main()
{
    ft_putnbr_fd(42, 1);
}