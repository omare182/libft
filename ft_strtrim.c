#include "libft.h"
int is_set(char c, char const *set)
{
    int i;

    i = 0;
    while(set[i])
    {
        if(set[i] == c)
            return (1);
        i++;
    }
    return (0);
}
char *ft_strtrim(char const *s1, char const *set)
{
    size_t end;
    size_t i;
    size_t start;
    char *new;
    

    start = 0;
    if(!s1)
        return (NULL);
    if(!set)
        return (NULL);
    while( is_set(s1[start],set) == 1 && s1[start])
        start++;
    end = ft_strlen(s1) - 1;
    while(end > start && is_set(s1[end],set) == 1)
        end--;
    i = 0;
    new = malloc(end - start + 1);
    if(!new)
        return (NULL);
    while(start <= end)
    {
        new[i] = s1[start];
        start++;
        i++;
    }
    new[i] = '\0';
    return (new);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set);

static int	g_tests = 0;
static int	g_failed = 0;

static void	test_strtrim(const char *name, const char *s1,
		const char *set, const char *expected)
{
	char	*result;

	g_tests++;
	result = ft_strtrim(s1, set);
	if (result == NULL)
	{
		printf("FAIL | %s | returned NULL\n", name);
		g_failed++;
		return ;
	}
	if (strcmp(result, expected) != 0)
	{
		printf("FAIL | %s | expected: \"%s\", got: \"%s\"\n",
			name, expected, result);
		g_failed++;
	}
	else
		printf("OK   | %s | \"%s\"\n", name, result);
	free(result);
}

static void	test_long_string(void)
{
	char	*s1;
	char	*result;
	int		i;
	int		ok;

	s1 = malloc(10003);
	if (s1 == NULL)
	{
		printf("SKIP | long string | allocation failed\n");
		return ;
	}
	s1[0] = 'x';
	s1[1] = 'x';
	i = 2;
	while (i < 10002)
	{
		s1[i] = 'A';
		i++;
	}
	s1[10002] = '\0';
	result = ft_strtrim(s1, "x");
	g_tests++;
	ok = 1;
	if (result == NULL || strlen(result) != 10000)
		ok = 0;
	if (ok && (result[0] != 'A' || result[9999] != 'A'
			|| result[10000] != '\0'))
		ok = 0;
	if (ok)
		printf("OK   | long string (10000 retained characters)\n");
	else
	{
		printf("FAIL | long string\n");
		g_failed++;
	}
	free(result);
	free(s1);
}

static void	test_independent_copy(void)
{
	char	s1[] = "xxhello xx";
	char	*result;

	result = ft_strtrim(s1, "x ");
	g_tests++;
	if (result == NULL)
	{
		printf("FAIL | independent copy | returned NULL\n");
		g_failed++;
		return ;
	}
	s1[2] = 'Y';
	if (strcmp(result, "hello") == 0)
		printf("OK   | independent copy\n");
	else
	{
		printf("FAIL | independent copy\n");
		g_failed++;
	}
	free(result);
}

int	main(void)
{
	printf("\n=== BASIC TESTS ===\n");
	test_strtrim("basic", "xxHello Worldxx", "x", "Hello World");
	test_strtrim("trim start", "xxxhello", "x", "hello");
	test_strtrim("trim end", "helloxxx", "x", "hello");
	test_strtrim("trim both", "xxxhelloxxx", "x", "hello");
	test_strtrim("nothing to trim", "hello", "x", "hello");

	printf("\n=== EMPTY STRING TESTS ===\n");
	test_strtrim("both empty", "", "", "");
	test_strtrim("empty s1", "", "abc", "");
	test_strtrim("empty set", "hello", "", "hello");
	test_strtrim("empty s1 and nonempty set", "", "x", "");
	test_strtrim("single char removed", "x", "x", "");
	test_strtrim("single char retained", "a", "x", "a");

	printf("\n=== SET CONTAINS MULTIPLE CHARACTERS ===\n");
	test_strtrim("multiple chars both ends", "abcHello Worldcba",
		"abc", "Hello World");
	test_strtrim("different chars at edges", "abchellocba",
		"abc", "hello");
	test_strtrim("mixed edge characters", "abchellocba",
		"acb", "hello");
	test_strtrim("set order changed", "abcHello Worldcba",
		"cba", "Hello World");
	test_strtrim("all characters in set", "abcabc", "abc", "");
	test_strtrim("all same chars", "aaaaaa", "a", "");
	test_strtrim("repeated set chars", "aaabbbhello bbbaaa",
		"ab ", "hello");

	printf("\n=== MIDDLE CHARACTERS MUST REMAIN ===\n");
	test_strtrim("x in middle", "xxhello xther", "x", "hello xther");
	test_strtrim("set chars in middle", "abcHello catcba",
		"abc", "Hello cat");
	test_strtrim("spaces in middle", "  hello  world  ",
		" ", "hello  world");
	test_strtrim("multiple matching chars inside",
		"xxaxxbxxcxx", "x", "axxbxxc");

	printf("\n=== WHITESPACE TESTS ===\n");
	test_strtrim("spaces", "   hello   ", " ", "hello");
	test_strtrim("tabs", "\t\thello\t", "\t", "hello");
	test_strtrim("newlines", "\n\nhello\n", "\n", "hello");
	test_strtrim("space and tab", " \t hello \t ", " \t", "hello");
	test_strtrim("carriage return", "\rhello\r", "\r", "hello");
	test_strtrim("mixed whitespace", " \t\nhello\n\t ",
		" \t\n", "hello");

	printf("\n=== SPECIAL CHARACTERS ===\n");
	test_strtrim("digits", "123hello321", "123", "hello");
	test_strtrim("punctuation", "!@#hello#@!", "!@#", "hello");
	test_strtrim("slashes", "///home/user///", "/", "home/user");
	test_strtrim("brackets", "[[[hello]]]", "[]", "[hello]]]");
	test_strtrim("plus and minus", "+-42-+", "+-", "42");
	test_strtrim("periods", "...file.txt...", ".", "file.txt");
	test_strtrim("underscores", "___hello___", "_", "hello");

	printf("\n=== STRING BOUNDARIES ===\n");
	test_strtrim("one char at start", "xabc", "x", "abc");
	test_strtrim("one char at end", "abcx", "x", "abc");
	test_strtrim("two chars total", "xx", "x", "");
	test_strtrim("no trim at either edge", "abc", "x", "abc");
	test_strtrim("only first edge matches", "xxhello", "x", "hello");
	test_strtrim("only last edge matches", "helloxx", "x", "hello");

	printf("\n=== UTF-8 TESTS ===\n");
	test_strtrim("accented chars", "éhelloé", "é", "hello");
	test_strtrim("Arabic text", "مرحبابكمرحبا", "مرحبا", "بك");
	test_strtrim("emoji", "🔥hello🔥", "🔥", "hello");

	printf("\n=== MEMORY TESTS ===\n");
	test_independent_copy();

	printf("\n=== LONG STRING TEST ===\n");
	test_long_string();

	printf("\n=== FINAL RESULTS ===\n");
	printf("Total tests: %d\n", g_tests);
	printf("Passed:      %d\n", g_tests - g_failed);
	printf("Failed:      %d\n", g_failed);
	return (g_failed != 0);
}
