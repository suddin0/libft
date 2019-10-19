#include "ft_string.h"
#include <stdio.h>

static void priv_str_pack_list_free(t_string *str)
{
	t_priv_string_pack *node;
	t_priv_string_pack *next;

	if(!str)
		return ;

	node = str->node_start;
	next = NULL;

	while(node)
	{
		next = node->next;
		ft_memdel((void *)&node);
		node = next;
	}
}

void priv_data_free(t_priv_data *data)
{
	if(data->data)
		ft_memdel((void **)&(data->data));
}

void str_free(t_string *string)
{
	if(!string)
		return ;
	priv_str_pack_list_free(string);
	priv_data_free(&(string->data));
	ft_memdel((void *)&string);
}
