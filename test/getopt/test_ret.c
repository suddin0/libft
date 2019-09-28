#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int a = 0;
	static struct option longopts[] = {
		{ "long",		no_argument,  NULL,   'l'},
		{ "all",		no_argument,  NULL,   'a'},
		{ "allmost-all",no_argument, NULL,    'A'},
		{ "revers",		no_argument, NULL,    'r'},
		{ "recursive",	no_argument, NULL,    'R'},
		{ NULL,         0,             NULL,   0 }
	};

	while((a = getopt_long(argc, argv, "+aAlrR", longopts, NULL)) != -1)
	{
		printf("--> [%c] : %d \n", isprint(a) ? a : ' ', a);
	}

	printf(" optind [%d]  [%s]\n", optind, argv[optind]);

	return(0);
}

