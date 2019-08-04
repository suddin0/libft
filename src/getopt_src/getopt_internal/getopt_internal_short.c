#include "ft_getopt.h"

/*
	The following function searches a reference to the given char and retern
	the address where the char was found. It was created to not use `ft_strchr`
	because `ft_strchr` didn't seems to handle a `NULL` parameter as we need in
	this situation.
*/

char *optchr(char *str, char c)
{
	while(str && *str)
	{
		if(*str == c)
			return(str);
		str++;
	}
	return(NULL);
}


/*
	The following function manages internal variables so we can keep track of
	where we are now and depending on the situation where we should be for the
	next call thus changes the optind (option index) and nextchar's value
*/

void set_getopt_data_short(t_getopt_internal_args arg)
{
	int arr_index; /* Indicate the index of the element in the array */
	int elm_index; /* Indicate the index of the element in the element */

	arr_index = arg.getopt_data->optind;
	elm_index = arg.getopt_data->nextchar;

	/*
		If we have reached the end of the string then go to the next array
		element and set the nextchar to 0 so it can start over.

		Else set the nextchar to the next element of string.
	*/
	if(arg.argv[arr_index][elm_index + 1] == '\0')
	{
		argv_mutate(arg, arg.getopt_data->optind);
		arg.getopt_data->optind++;
		arg.getopt_data->nextchar = 0;
	}
	else
		arg.getopt_data->nextchar++;
}


/*
	The following function checks if an argument is required or not, if so then
	what type of argument (mandatory or optional)

	if mandatory then returns `OPT_ARG_MANDATORY`
	if optional then returns `OPT_ARG_OPTIONAL`
	else returns OPT_ARG_NONE.
*/
int check_optarg(char *opt)
{
	int val;

	val = OPT_ARG_NONE;
	if(!opt)
		return(OPT_ARG_NONE);

	/* skip the opt char that is being indicated */
	opt++;
	if(*opt == ':')
	{
		opt++;
		val = OPT_ARG_MANDATORY;
	}

	if(*opt == ':')
	{
		opt++;
		val = OPT_ARG_OPTIONAL;
	}
	return(val);
}

int short_arg(t_getopt_internal_args arg, t_getopt_data *d, int argtype, int c)
{
	/* If argument is optional */
	if(argtype == OPT_ARG_OPTIONAL)
	{
		if(arg.argv[d->optind][d->nextchar + 1])
			d->optarg = &(arg.argv[d->optind][d->nextchar + 1]);
	}
	/* If Mandatory */
	else if(argtype == OPT_ARG_MANDATORY)
	{
		/* If there is something after the current index */
		if(arg.argv[d->optind][d->nextchar + 1])
			d->optarg = &(arg.argv[d->optind][d->nextchar + 1]);
		/* if there is nothing on the current string but next argument exists */
		else if((d->optind + 1) < arg.argc && arg.argv[d->optind])
		{
			argv_mutate(arg, d->optind);
			d->optind++;
			d->optarg = arg.argv[d->optind];
		}
		/* No argument was provided for the option */
		else
		{
			if(arg.print_error)
				ft_dprintf( FT_STDERR_FD, "%s: option requires an argument -- '%c'\n", arg.argv[0], c);
			d->optopt = c;
			d->optind++;
			d->nextchar = 0;
			return(arg.colon ? OPT_ERROR_MISS_ARG : OPT_ERROR_DEFAULT);
		}
	}
	argv_mutate(arg, d->optind);
	d->optind++;
	d->nextchar = 0;
	return(c);
}

int getopt_internal_short(t_getopt_internal_args arg, t_getopt_data *getopt_data)
{
	char	c;			/* Character found in the optstring */
	char	*optstr;	/* contains the output of ft_strchr */
	int		optarg;

	/* Should i really need to send -1 here ???? ** VERIFY ** */
	if(!arg.optstring)
		return(-1);

	/* check if the option exists in the opt string */
	c = arg.argv[arg.getopt_data->optind][arg.getopt_data->nextchar];
	optstr = optchr((char *)arg.optstring, c);

	/* If option do not exists in the optstring then set the error and stop */
	if(!optstr || c == ':' || c == ';')
	{
		/* Option wasn't found in the `optstring` */
		if(arg.print_error)
			ft_dprintf( FT_STDERR_FD, "%s: invalid option -- '%c'\n", arg.argv[0], c);
		arg.getopt_data->optopt = c;
		/* set the global variables and return appropriately */
		set_getopt_data_short(arg);

		return(OPT_ERROR_DEFAULT);
	}

	/* found the option in optstring */

	/* The option was found but an argument is required */
	optarg = check_optarg(optstr);


	/* If some kind of  option is required then manage it */
	if(optarg != OPT_ARG_NONE)
		return(short_arg(arg, getopt_data, optarg, c));


	/* No argument is required */
	set_getopt_data_short(arg);
	return(c);
}
