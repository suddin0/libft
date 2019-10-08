#include "ft_string.h"

t_priv_string_pack	*priv_string_pack_new(void)
{
	t_priv_string_pack *str_pack;

	str_pack = (t_priv_string_pack *)ft_memalloc(sizeof(t_priv_string_pack));
	if(!str_pack)
		return (NULL);

	str_pack->len = 0;

	str_pack->next = NULL;
	str_pack->prev = NULL;
	return(str_pack);
}
