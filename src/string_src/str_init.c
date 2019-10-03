#include "ft_string.h"

int	str_init(t_string *string)
{
	t_internal_string_pack *str_pack;

	if(!string)
		return ;

	str_pack = internal_string_pack_new();
	if(!str_pack)
		return (-1);
	string->data = NULL;
	string->data_len = 0;
	string->cur = 0;
	string->len = 0;

	string->string = str_pack;
	string->last_node = str_pack;
	return(0);
}
