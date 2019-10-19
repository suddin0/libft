#include "ft_string.h"

int priv_str_pack_add_char(t_string *string, char ch)
{
	t_priv_string_pack *pack;

	pack = NULL;
	if(!string)
		return (STRING_ERROR);
	if(!(string->node_cur) || string->node_cur->len == PRIVATE_STRING_PACK_DATA_SIZE)
	{
		if(priv_str_pack_node_add(string) == STRING_ERROR)
			return (STRING_ERROR);
	}

	pack = string->node_cur;
	pack->data[pack->len] = ch;
	pack->len++;
	return(STRING_SUCCESS);
}
