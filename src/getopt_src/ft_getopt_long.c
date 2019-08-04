#include "ft_getopt.h"


int ft_getopt_long(t_getopt_arg arg, const char *optstring, \
	const t_option *longopts, int *longindex)
{
	t_getopt_internal_args	internal_args;	/* Arguments to pass to `getopt_internal` */
	t_optvar				*optvar;		/* `Globals` */
	t_getopt_data			*getopt_data;
	int						result;

	optvar = get_optvar();
	getopt_data = get_getopt_data();
	getopt_data->optind = optvar->optind;
	getopt_data->opterr = optvar->opterr;
	internal_args_init(&internal_args, arg, optstring, longopts);
	result = getopt_internal(internal_args, longindex);
	optvar->optind = getopt_data->optind;
	optvar->optarg = getopt_data->optarg;
	optvar->optopt = getopt_data->optopt;
	return (result);
}
