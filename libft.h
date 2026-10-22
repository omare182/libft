# ifndef libft_h
# define libft_h
# include <unistd.h>
# include <stdlib.h>

int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *str);
void *ft_memset(void *p, int c, size_t len);
void ft_bzero(void *s, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strdup(const char *s);

//part :2

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char c));
void ft_striteri(char *s, void (*f)(unsigned int, char *))
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

// part 3 : 

typedef struct s_list
{
void *content;
struct s_list *next;
}





#endif