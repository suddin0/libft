#include "main.h"

char			shortopt[] = "abcd::efa-:ABC::EF:GHI12::3456:789:0+?";
struct option	longopt[]	=
{
	{"a",		no_argument,		0,  'A'},
	{"aa",		no_argument,		0,  'A'},
	{"aaa",		optional_argument,	0,  'A'},
	{"aaaa",	no_argument,		0,  0},
	{"aaaaa",	no_argument,		0,  1},
	{"aaaaaa",	no_argument,		0,  2},
	{"boclata",	no_argument,		0,  2},
	{"color",	no_argument,		0,  3},
	{"clackxon",required_argument,	0,  4},
	{0,         0,           0,   0 }
};


int main(int argc, char **argv, char **envp)
{
	int gopt		= -1;
	int fopt		= -1;

	int run			= 1;

	int glongind	= -1;
	int flongind	= -1;

	/* Duplicate the current argv */
	char **gargv	= argvdup(argc, argv);
	char **fargv	= argvdup(argc, argv);
	t_getopt_arg arg= {argc, argv};

	/* unbufferize outputs (for system printf) */
	fflush(stderr);
	fflush(stdout);

	/* verify if the duplication worked or not */
	if(!gargv || !fargv)
	{
		argv_free(argc, gargv);
		argv_free(argc, fargv);
		return(1);
	}


	while(run)
	{
		gopt = getopt_long(argc, argv, shortopt, longopt, &glongind);
		fopt = ft_getopt_long(arg, shortopt, (t_option*)longopt, &flongind);

		if(check_diff(gopt, fopt, argc, argv, gargv, fargv, longopt, glongind, flongind) == STOP)
			break ;

		glongind	= -1;
		flongind	= -1;
	}

	argv_free(argc, gargv);
	argv_free(argc, fargv);
	return 0;
}
