#include "ft_string.h"

t_string			*str_new(const unsigned char *str)
{
	t_string *string;

	string = ft_memalloc(sizeof(t_string));
	if(!string)
		return (NULL);
	if(priv_str_init(string))
	{
		ft_memdel((void **)&string);
		return NULL;
	}
	if(str)
		str_add(string, str);
	return (string);
}
