#include "main.h"

char **argvdup(int argc, char **argv)
{
	char **nargv = NULL;

	nargv = (char**)malloc((argc + 1) * sizeof(char *));
	if(!nargv)
	{
		printf("[-] Error duplicating argv: %s", strerror(errno));
		return(NULL);
	}

	for (int i = 0; i < argc; i++)
		nargv[i] = NULL;
	for (int i = 0; i < argc; i++)
		nargv[i] = strdup(argv[i]);
	return(nargv);
}
