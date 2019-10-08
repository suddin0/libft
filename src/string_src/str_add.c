#include "ft_string.h"

int string_pack_add_char(t_string *string, t_priv_string_pack *pack, unsigned char ch)
{
	t_priv_string_pack *extra;
	t_priv_string_pack *next;

	if(!pack)
		return (STRING_ERROR);
	next = NULL;
	extra = NULL;
	/* If pack is full tehn create a new pack */
	if(pack->len == PRIVATE_STRING_PACK_DATA_SIZE)
	{
		extra = priv_string_pack_new();
		if(!extra)
			return (STRING_ERROR);
		next = pack->next;
		pack->next = extra;
		if(next)
			next->prev = extra;
		string->node_cur = extra;
		pack = extra;
	}

	pack->data[pack->len] = ch;
	pack->len++;
	return(STRING_SUCCESS);
}

ssize_t priv_str_add(t_string *dest, const unsigned char *src)
{
	size_t i;

	if(!dest || !src)
		return (-1);

	while(src[i])
	{
		if(string_pack_add_char(dest, dest->node_cur, src[i]))
			return (STRING_ERROR);
		i++;
	}
	return (i);
}

#include <stdio.h>

void str_add(t_string *dest, const unsigned char *src)
{
	printf("%p : %p\n", dest, src);
	if(!dest || !src)
		return ;
	/*
		Check whather the index was move or not.
		if it was then manage it.
	*/

	printf("---- %p : %p\n", dest, src);

	/* If we are tearing a singe string */
	priv_str_add(dest, src);

}
