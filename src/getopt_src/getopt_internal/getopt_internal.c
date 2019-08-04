#include "ft_getopt.h"

#include <stdio.h>

int getopt_internal(t_getopt_internal_args arg,  int *longindex)
{
	t_getopt_data			*getopt_data;
	int						opt_type;

	getopt_data = get_getopt_data();
	getopt_data->optarg = NULL;

	/*
		If there are no arguments then stop.

		If for some reason we surpassed the number of arguments given.

		If arguments are passed and the special `--` option was encountered
		or for some reasion the `t_getopt_data.finished` is active then stop.
	*/
	if(arg.argc < 1 || getopt_data->optind >=  arg.argc)
		return (getopt_end(arg));

	/*
		If we are in the begining of an argument then check if it is a long or
		short option otherwise by default it is a short option.
	*/
	if(getopt_data->nextchar == 0)
	{
		/* get the next option if found else stop */
		opt_type = set_next_opt(arg, arg.argc, arg.argv);
		if(opt_type == OPT_TYPE_ERROR || opt_type == OPT_TYPE_END)
			return(getopt_end(arg));
		else if(opt_type == OPT_TYPE_ARG /* Or i longopt == NULL */)
			return(opt_type);
		else if(opt_type == OPT_TYPE_SHORT || (opt_type == OPT_TYPE_LONG && arg.longopts == NULL))
		{
			/* jump the first `-` character */
			getopt_data->nextchar++;
			return(getopt_internal_short(arg, getopt_data));
		}
		else if(opt_type == OPT_TYPE_LONG)
		{
			getopt_data->nextchar += 2;
			return(getopt_internal_long(arg, getopt_data, longindex));
		}
	}
	else
		return(getopt_internal_short(arg, getopt_data));
	return (getopt_end(arg));
}
