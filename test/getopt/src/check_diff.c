#include "main.h"


int check_diff(
	int ret_getopt,
	int ret_ft_getopt,
	int argc,
	char **argv,
	char **argv_getopt,
	char **argv_ft_getopt,
	struct option	longopt[],
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
