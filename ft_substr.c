/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omel-kas <omel-kas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:42:38 by omel-kas          #+#    #+#             */
/*   Updated: 2026/10/15 23:50:32 by omel-kas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new;
	size_t i;
	size_t len_s;

	len_s = 0;
	i = 0; 
	if(s  == NULL)
		return (NULL); 
	while(s[len_s])
		len_s++;
	if(start >= len_s || len_s == 0 || len == 0){
		new = malloc(1);
		if(!new)
			return (NULL);
		*new =  '\0';
		return (new);
	}
	if(len > len_s - start)
		len = len_s - start;
	new = malloc((sizeof(char)*(len + 1)));
	if(!new)
		return (NULL);	
	while(i < len )
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}	











// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdint.h>
// #include <limits.h>
// #include "libft.h"

// static void	t(int n, char const *s, unsigned int start, size_t len, char const *exp)
// {
// 	char	*r;

// 	r = ft_substr(s, start, len);
// 	if (!r || !exp)
// 		printf("%d. ft: %s | exp: %s | %s\n", n,
// 			r ? r : "NULL", exp ? exp : "NULL", (!r && !exp) ? "OK" : "KO");
// 	else
// 		printf("%d. ft: \"%s\" | exp: \"%s\" | %s\n", n, r, exp,
// 			strcmp(r, exp) == 0 ? "OK" : "KO");
// 	free(r);
// }

// int main(void)
// {
// 	char s1[] = "abc\0def";

// 	t(1,  "hello world", 6, 5, "world");
// 	t(2,  "hello world", 6, 100, "world");
// 	t(3,  "hello world", 0, 5, "hello");
// 	t(4,  "hello world", 0, 11, "hello world");
// 	t(5,  "hello world", 0, 1000, "hello world");
// 	t(6,  "hello world", 3, 0, "");
// 	t(7,  "hello world", 11, 5, "");
// 	t(8,  "hello world", 20, 5, "");
// 	t(9,  "hello world", 10, 1, "d");
// 	t(10, "hello world", 10, 5, "d");
// 	t(11, "", 0, 5, "");
// 	t(12, "", 0, 0, "");
// 	t(13, "", 5, 5, "");
// 	t(14, "a", 0, 1, "a");
// 	t(15, "a", 1, 1, "");
// 	t(16, "a", 0, 0, "");
// 	t(17, "42 network", 3, 7, "network");
// 	t(18, "  spaces  ", 2, 6, "spaces");
// 	t(19, "0123456789", 2, 3, "234");
// 	t(20, "0123456789", 9, 1, "9");
// 	t(21, "hello world", 0, SIZE_MAX, "hello world");
// 	t(22, "hello world", 6, SIZE_MAX, "world");
// 	t(23, "hello world", UINT_MAX, 5, "");
// 	t(24, "hello world", UINT_MAX, SIZE_MAX, "");
// 	t(25, "hello world", 5, 1, " ");
// 	t(26, s1, 1, 5, "bc");              /* stops at the first '\0' */
// 	t(27, "tripouille", 0, 42000, "tripouille");
// 	t(28, "tripouille", 1, 1, "r");
// 	t(29, "tripouille", 100, 1, "");
// 	t(30, NULL, 0, 5, NULL);
// 	t(31, NULL, 0, 0, NULL);
// }
//////////////////onther test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"

static void	t(int n, char const *name, char const *s,
			unsigned int start, size_t len, char const *exp)
{
	pid_t	pid;
	int		status;
	char	*r;

	printf("%d. %-28s : ", n, name);
	fflush(stdout);
	pid = fork();
	if (pid == 0)
	{
		r = ft_substr(s, start, len);
		if (!r && !exp)
			exit(0);
		if (!r || !exp)
			exit(1);
		exit(strcmp(r, exp) != 0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		printf("CRASH (signal %d)\n", WTERMSIG(status));
	else if (WEXITSTATUS(status) == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

int main(void)
{
	/* Error 1: s == NULL */
	t(1, "NULL string",              NULL, 0, 5, NULL);
	t(2, "NULL string, len 0",       NULL, 0, 0, NULL);

	/* Error 2: start == strlen */
	t(3, "start == strlen",          "hello", 5, 3, "");
	t(4, "start == strlen, len 0",   "hello", 5, 0, "");
	t(5, "start == strlen (1 char)", "a", 1, 1, "");

	/* Error 3: len bigger than the remaining chars */
	t(6, "len > remaining",          "hello", 3, 100, "lo");
	t(7, "len > remaining (+1)",     "hello", 4, 2, "o");
	t(8, "len way too big",          "hello world", 6, 42000, "world");
	t(9, "len = strlen from start 1", "hello", 1, 5, "ello");

	/* Error 4: len = SIZE_MAX (malloc overflow) */
	t(10, "len = SIZE_MAX",          "hello", 0, SIZE_MAX, "hello");
	t(11, "len = SIZE_MAX, start 2", "hello", 2, SIZE_MAX, "llo");
		t(12, "len = SIZE_MAX, start end", "hello", 5, SIZE_MAX, "");

	/* Extra: start very big */
	t(13, "start = UINT_MAX",        "hello", UINT_MAX, 5, "");
	t(14, "start = UINT_MAX, SIZE_MAX", "hello", UINT_MAX, SIZE_MAX, "");

	/* Extra: should already pass */
	t(15, "normal case",             "hello world", 6, 5, "world");
	t(16, "empty string",            "", 0, 5, "");
	t(17, "len = 0",                 "hello", 2, 0, "");

	return (0);
}