#include "libft.h"
t_list *ft_lstnew(void *content)
{
    t_list *n = malloc(sizeof(t_list));
    if(!n)
        return (NULL);
    n->content = content;
    n->next = NULL;
    return (n);
}
