#include "main.h"


void argv_free(int argc, char **argv)
{
	if(!argv)
		return ;
	int i = 0;
	while(i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
