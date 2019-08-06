#include "ft_getopt.h"

static void optvar_init(t_optvar *optvar)
{
	optvar->initialized = GETOPT_INITIALIZED;
	optvar->optarg = NULL;
	optvar->optind = 1;
	optvar->opterr = GETOPT_ERROR_SHOW;
	optvar->optopt = 0;
}

t_optvar *get_optvar()
{
	static t_optvar optvar;

	if(!optvar.initialized)
		optvar_init(&optvar);
	return(&optvar);
}
