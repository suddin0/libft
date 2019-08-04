#include "ft_getopt.h"

// static void swap_index(char **argv, int a, int b)
// {
// 	char *tmp;
//
// 	tmp = argv[a];
// 	argv[a] = argv[b];
// 	argv[b] = tmp;
// }


// static void push_non_opt(int argc, char **argv, int index)
// {
// 	char *non_opt;
// 	char *tmp;
// 	int i;
//
// 	if(!argv || index >= argc)
// 		return ;
// 	non_opt = argv[index];
// 	i = index;
// 	while(i + 1 != argc)
// 	{
// 		swap_index(argv, i, i + 1);
// 		i++;
// 	}
// }

static int set_non_opt_arg(t_getopt_internal_args int_arg, int index)
{
	/* Set up getopt_data variables */
	// printf("### %d : %s\n", index, int_arg.argv[index]);
	int_arg.getopt_data->optarg = int_arg.argv[index];
	int_arg.getopt_data->optind++;
	int_arg.getopt_data->nextchar = 0;
	return(OPT_TYPE_ARG);
}

int set_next_opt(t_getopt_internal_args int_arg, int argc, char **argv)
{
	// int counter;
	int opt_type;

	if(!argv || int_arg.getopt_data->optind >= argc)
		return (OPT_TYPE_ERROR);
	// counter = index;
	opt_type = OPT_TYPE_ERROR;
	while(int_arg.getopt_data->optind < argc)
	{

		// printf("Insid set_next_opt LOOP counter %d\n", counter);
		opt_type = option_type(argv[int_arg.getopt_data->optind]);
		if(int_arg.opt_treat == OPT_TREAT_POSIXLY_CORRECT && opt_type == OPT_TYPE_NONE)
			/* Set up getopt_data variables */
			return(GETOPT_END);
		else if(int_arg.opt_treat == OPT_TREAT_NON_OPT_ARG && opt_type == OPT_TYPE_NONE)
			/* Set up getopt_data variables */
			return(set_non_opt_arg(int_arg, int_arg.getopt_data->optind));
		/* If found `--` */
		if(opt_type == OPT_TYPE_END)
		{
			/* Set up getopt_data variables */
			argv_mutate(int_arg, int_arg.getopt_data->optind);
			return(GETOPT_END);
		}
		else if(opt_type != OPT_TYPE_NONE)
			return(opt_type);
		// push_non_opt(argc, argv, index);
		int_arg.getopt_data->optind++;
	}
	return(OPT_TYPE_ERROR);
}
