#include "ft_string.h"

static void priv_init_data(t_priv_data *data)
{
	data->data = NULL;
	data->data_len = 0;
	data->data_size = 0;
}

static void priv_init_index(t_priv_index *index)
{
	index->index = 0;
	index->index_moved = 0;
}

int	priv_str_init(t_string *string)
{
	if(!string)
		return (-1);

	priv_init_data(&(string->data));
	priv_init_index(&(string->index));
	string->len = 0;
	string->node_start = NULL;
	string->node_cur = NULL;
	string->node_last = NULL;
	return(0);
}
