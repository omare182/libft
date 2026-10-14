# ifndef libft_h
# define libft_h
# include <unistd.h>


int ft_isalpha(int c);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_strlen(char *str);
void *ft_memset(void *p, int c, size_t len);
void ft_bzero(void *s, size_t n);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);





#endif