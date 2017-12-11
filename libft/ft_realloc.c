#include "libft.h"

char		*ft_realloc(char *str, size_t new_len)
{
	char	*new_str;
	
	if (!str || !new_len)
		return (NULL);
	new_str = ft_memalloc(new_len);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, str);
	free(str);
	return (new_str);
}
