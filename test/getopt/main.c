#include "main.h"


char			short_opt[] = "abcd::efa-:";
struct option	longopt[]	=
{
	// {"a",		no_argument,		0,  'A'},
	// {"aa",		no_argument,		0,  'A'},
	{"aaa",		optional_argument,	0,  'A'},
	{"aaaa",	no_argument,		0,  0},
	{"aaaaa",	no_argument,		0,  1},
	{"aaaaaa",	no_argument,		0,  2},
	{"boclata",	no_argument,		0,  2},
	{"bclora",	no_argument,		0,  'r'},
	{0,         0,           0,   0 }
};


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


int compare_argv(int argc, char **a, char **b)
{
	int i = 0;
	int error = CONTINUE;

	if(!a || !b)
	{
		printf("\e[38;5;197m[-] Error: arguments %c is NULL\n", !a ? 'a' : 'b');
		return(-1);
	}

	while(i < argc)
	{
		if(optarg_cmp(a[i], b[i]) != 0)
		{
			if(error == CONTINUE)
			{
				ft_printf("Error with argument organization:\n");
				ft_printf("%15.15s | %15.15s\n", "Getopt", "Ft_getopt");
			}
			ft_printf("%15.15s | %s%15.15s%s\n", a[i], RED, b[i], WHITE);
			error = STOP;
		}
		i++;
	}

	return (error);
}

int check_diff(
	int ret_getopt,
	int ret_ft_getopt,
	int argc,
	char **argv,
	char **argv_getopt,
	char **argv_ft_getopt,
	int glongind,
	int flongind
)
{
		char *ft_optarg	= *(get_optarg());
		int ft_optind	= *(get_optind());
		int ft_opterr	= *(get_opterr());
		int ft_optopt	= *(get_optopt());

		int strcmp_result	= optarg_cmp(optarg ,ft_optarg);
		int error			= CONTINUE;

		if(
			ret_getopt != ret_ft_getopt	||
			strcmp_result != 0			||
			optind != ft_optind			||
			optopt != ft_optopt			||
			glongind != flongind
		)
		{
			ft_printf("    RETURN  |   OPTIND  |    OPTOPT   |   OPTERR   |    OPTARG   |    LONGOPT|\n");
			ft_printf("------------|-----------|-------------|------------|-------------|-----------|\n");
			/* getopt (standard library) informations */
			ft_printf(" %10d |", ret_getopt < 0 ? ret_getopt + 0 : ret_getopt ); 											/* Return */
			ft_printf(" %9d |", optind);												/* optind */
			ft_printf(" %11c |", optopt < '0' ? optopt + '0' : optopt);					/* optopt */
			ft_printf(" %10d |", opterr);												/* opterr */
			ft_printf(" %11s |", optarg);												/* optarg */
			ft_printf(" %7s |", glongind > 0 ? longopt[glongind].name : "~(empty)~");	/* longopt */
			ft_printf("\n");

			/* ft_getopt (local) */
			ft_printf("%s %10d \e[38;5;15m|", ret_ft_getopt != ret_getopt	? RED : WHITE , ret_ft_getopt < 0 ? ret_ft_getopt + 0 : ret_ft_getopt); /* Return */
			ft_printf("%s %9d \e[38;5;15m|", ft_optind != optind 			? RED : WHITE , ft_optind);		/* optind */
			ft_printf("%s %11c \e[38;5;15m|", ft_optopt != optopt			? RED : WHITE , ft_optopt < '0' ? ft_optopt + '0' : ft_optopt);		/* optopt */
			ft_printf("%s %10d \e[38;5;15m|", ft_opterr != opterr			? RED : WHITE , ft_opterr);		/* opterr */
			ft_printf("%s %11s \e[38;5;15m|", strcmp_result != 0				? RED : WHITE , ft_optarg);		/* optarg */
			ft_printf("%s %7s \e[38;5;15m|", flongind != glongind			? RED : WHITE , flongind > 0 ? longopt[flongind].name : "~(empty)~"); /* longopt */
			ft_printf("\n");
			error = STOP;
		}
		if(compare_argv(argc, argv_getopt, argv_ft_getopt) == STOP)
			error = STOP;


		if(ret_getopt == -1 || ret_ft_getopt == -1)
			error = STOP;

		return(error);
}


char *get_error(int fd)
{
	char c;
	while(read(fd, &c, 1) > 0)
	{
		ft_printf("-> %c", c);
	}

	return(NULL);
}

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
		gopt = getopt_long(argc, argv, short_opt, longopt, &glongind);
		fopt = ft_getopt_long(arg, short_opt, (t_option*)longopt, &flongind);

		if(check_diff(gopt, fopt, argc, argv, gargv, fargv, glongind, flongind) == STOP)
			break ;

		glongind	= -1;
		flongind	= -1;
	}

	argv_free(argc, gargv);
	argv_free(argc, fargv);
	return 0;
}
