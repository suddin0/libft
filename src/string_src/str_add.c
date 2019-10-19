#include "ft_string.h"


void str_add(t_string *dest, const char *src)
{
	if(!dest || !src)
		return ;
	/*
		Check whather the index was move or not.
		if it was then manage it.
	*/


	/* If we are tearing a singe string */
	priv_str_add(dest, src);

}
