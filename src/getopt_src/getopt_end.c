#include "ft_getopt.h"

int getopt_end(t_getopt_internal_args arg)
{
	if(arg.opt_treat == OPT_TREAT_MUTATE)
		arg.getopt_data->optind = arg.getopt_data->last_optind;
	return(GETOPT_END);
}
