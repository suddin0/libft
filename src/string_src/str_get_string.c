#include "ft_string.h"

#include <stdio.h>

char *str_get_string(t_string *string)
{
	t_priv_string_pack *node;
	size_t i;

	node = NULL;
	i = 0;

	if(!string)
		return (NULL);

	if(string->data.data_len < string->len)
	{
		if(string->data.data)
			ft_memdel((void **)&(string->data.data));

		string->data.data = (char*)ft_memalloc(sizeof(char) * (string->len + 1));
		if(!string->data.data)
			return(NULL);
		string->data.data_len = 0;
		string->data.data_size = string->len+1;
	}
	node = string->node_start;
	while(node)
	{
		ft_memcpy(&((string->data.data)[i]), node->data, node->len);
		i += node->len;
		node = node->next;
	}
	string->data.data_len = 1;
	ft_memset(&((string->data.data)[i]), 0, 1);
	return(string->data.data);
}
