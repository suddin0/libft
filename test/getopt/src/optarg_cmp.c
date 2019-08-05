#include "main.h"

int optarg_cmp(char *a, char *b)
{
	if(a == b)
		return 0;
	else if(a && !b)
		return 1;
	else if(!a && b)
		return 1;
	else if(a && b)
		return(strcmp(a, b));
}
