#include "ft_string.h"


/*
** The following function is used if there is no node exists in the string
** structure.
*/

static int priv_str_pack_node_new(t_string *string)
{
	t_priv_string_pack *node;

	if(!string || string->node_start)
		return (STRING_ERROR);
	node = priv_string_pack_new();
	if(!node)
		return (STRING_ERROR);
	string->node_start = node;
	string->node_cur = node;
	string->node_last = node;
	return (STRING_SUCCESS);
}

int priv_str_pack_node_add(t_string *string)
{
	t_priv_string_pack *node;
	t_priv_string_pack *nd;

	node = NULL;
	nd = NULL;
	if(!string)
		return (STRING_ERROR);
	/* If there was no current to begin with */
	if(!string->node_cur)
		return(priv_str_pack_node_new(string));
	if(!(node = priv_string_pack_new()))
		return (STRING_ERROR);
	nd = string->node_cur;
	/*
		if current node has a child then add the child to the newæy created node
		and set the previous node of the next node to the newly created node
	*/
	if(nd->next)
	{
		node->next = nd->next;
		nd->next->prev = node;
	}
	node->prev = nd;
	nd->next = node;

	/*
		if the current node was the last node then set the newly created as the
		last node as the newly created node is becoming the current node.
	*/
	if(nd == string->node_last)
		string->node_last = node;
	string->node_cur = node;
	return (STRING_SUCCESS);
}
