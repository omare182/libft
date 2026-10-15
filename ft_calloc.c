/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omel-kas <omel-kas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:37:04 by omel-kas          #+#    #+#             */
/*   Updated: 2026/10/15 21:39:55 by omel-kas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_calloc(size_t count, size_t size)
{
    char *new;
    size_t i;
    size_t total;

    if(size && (SIZE_MAX / size) < count)
        return (NULL);
    total = size * count;
    if (!total)
        total = 1;
    new = malloc(total);
    if(!new)
        return (NULL);
    i = 0;
    while(i < total)
        new[i++] = 0;
    return (new);
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "libft.h"

static void test(int n, size_t count, size_t size)
{
    void    *dirty;
    void    *ft;
    void    *std;
    int     same;

    dirty = malloc(1024);
    memset(dirty, 0xFF, 1024);
    free(dirty);

    ft = ft_calloc(count, size);
    std = calloc(count, size);
    same = 1;
    if (ft && std)
        same = (memcmp(ft, std, count * size) == 0);
    else if ((ft == NULL) != (std == NULL))
        same = 0;
    printf("%-3d ft: %-8s | std: %-8s | %s\n", n,
        ft ? "ptr" : "NULL", std ? "ptr" : "NULL", same ? "OK" : "KO");
    free(ft);
    free(std);
}

int main(void)
{
    test(1, 10, sizeof(int));
    test(2, 1, 1);
    test(3, 100, 1);
    test(4, 1, 100);
    test(5, 25, sizeof(int));
    test(6, 50, sizeof(char));
    test(7, 3, sizeof(long));
    test(8, 7, 13);
    test(9, 1000, 1);
    test(10, 0, 5);
    test(11, 5, 0);
    test(12, 0, 0);
    test(13, SIZE_MAX, 2);
    test(14, 2, SIZE_MAX);
    test(15, SIZE_MAX, SIZE_MAX);
    test(16, SIZE_MAX / 2 + 1, 2);
    test(17, 5000, 1);
    return (0);
}   