#include "ft_getopt.h"

char **get_optarg()
{
	t_optvar *optvar;

	optvar = get_optvar();
	return(&(optvar->optarg));
}

int *get_optind()
{
	t_optvar *optvar;

	optvar = get_optvar();
	return(&(optvar->optind));
}

int *get_opterr()
{
	t_optvar *optvar;

	optvar = get_optvar();
	return(&(optvar->opterr));
}

int *get_optopt()
{
	t_optvar *optvar;

	optvar = get_optvar();
	return(&(optvar->optopt));
}
