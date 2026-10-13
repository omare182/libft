/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omel-kas <omel-kas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:47:39 by omel-kas          #+#    #+#             */
/*   Updated: 2026/10/13 19:35:47 by omel-kas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    const unsigned char *s;
    unsigned char *d;
    size_t i = 0;

    s = (const unsigned char *)src;
    d = (unsigned char *)dst;
    if (d > s)
    {
        while(len > 0)
        {
            d[len - 1] = s[len - 1];         
            len--;
        }

    }
    else
    {
        while(i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (d);
}
#include <stdio.h>
int main(void)
{
    char s[] = "HELLO";
    char *dst = s + 1;
    char *src = s;
    ft_memmove(dst , src, 5);
    printf("%s\n%s\n", dst, src);
    return (0);


}