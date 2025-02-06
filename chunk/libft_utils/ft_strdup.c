#include "../include/push_swap.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	char	*ptr;

	if (!s1)
		return (NULL);
	dest = (char *) malloc(ft_strlen(s1) + 1);
	ptr = dest;
	if (!dest)
		return (NULL);
	while (*s1)
		*(dest++) = *(s1++);
	*dest = '\0';
	return (ptr);
}