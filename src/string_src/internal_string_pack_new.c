#include "ft_string.h"

t_internal_string_pack	*internal_string_pack_new(void)
{
	t_internal_string_pack *str_pack;

	str_pack = ft_memalloc(sizeof(t_string));
	if(!str_pack)
		return (NULL);

	str_pack->len = 0;

	str_pack->next = NULL;
	str_pack->prev = NULL;
	return(str_pack);
}
