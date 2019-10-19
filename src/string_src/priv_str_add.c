#include "ft_string.h"

ssize_t priv_str_add(t_string *dest, const char *src)
{
	size_t i;

	if(!dest || !src)
		return (-1);
	i = 0;
	while(src[i])
	{
		if(priv_str_pack_add_char(dest, src[i]) == STRING_ERROR)
			return (STRING_ERROR);
		dest->len++;
		i++;
	}
	return (i);
}
