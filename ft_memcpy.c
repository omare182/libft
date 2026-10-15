/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omel-kas <omel-kas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:37:29 by omel-kas          #+#    #+#             */
/*   Updated: 2026/10/15 21:37:30 by omel-kas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    const unsigned char *s;
    unsigned char *d;
    size_t i;

    i = 0;
    s = (const unsigned char *)src;
    d = (unsigned char *)dst;
    if (!src && !dst)
        return (NULL);
    while(i < n){
        d[i] = s[i];
        i++;
    }
    return (dst);
}