/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_internal_short.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:18:58 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:29:36 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include "ft_printf.h"
#include "libft.h"

/*
** The following function manages internal variables so we can keep track of
** where we are now and depending on the situation where we should be for the
** next call thus changes the optind (option index) and nextchar's value
**
**  arr_index : Indicate the index of the element in the array
**  elm_index : Indicate the index of the element in the element
**
** IF:
**  If we have reached the end of the string then go to the next array
**  element and set the nextchar to 0 so it can start over.
**
** ELSE:
**  Else set the nextchar to the next element of string.
*/

void	set_getopt_data_short(t_getopt_internal_args arg)
{
	int arr_index;
	int elm_index;

	arr_index = arg.getopt_data->optind;
	elm_index = arg.getopt_data->nextchar;
	if (arg.argv[arr_index][elm_index + 1] == '\0')
	{
		argv_mutate(arg, arg.getopt_data->optind);
		arg.getopt_data->optind++;
		arg.getopt_data->nextchar = 0;
	}
	else
		arg.getopt_data->nextchar++;
}

/*
** The following function checks if an argument is required or not, if so then
** what type of argument (mandatory or optional)
**
** if mandatory then returns `OPT_ARG_MANDATORY`
** if optional then returns `OPT_ARG_OPTIONAL`
** else returns OPT_ARG_NONE.
**
** a++ : skip the opt char that is being indicated
*/

int		check_optarg(char *opt)
{
	int val;

	val = OPT_ARG_NONE;
	if (!opt)
		return (OPT_ARG_NONE);
	opt++;
	if (*opt == ':')
	{
		opt++;
		val = OPT_ARG_MANDATORY;
	}
	if (*opt == ':')
	{
		opt++;
		val = OPT_ARG_OPTIONAL;
	}
	return (val);
}

/*
**  The following function is an extention of `short_arg`. It is created to
**  respect the 42 norm of 25 lime function max.
*/

int		short_arg_ext(t_getopt_internal_args arg, t_getopt_data *d, int c)
{
	int error;

	error = c;
	if (arg.argv[d->optind][d->nextchar + 1])
		d->optarg = &(arg.argv[d->optind][d->nextchar + 1]);
	else if ((d->optind + 1) < arg.argc && arg.argv[d->optind])
	{
		argv_mutate(arg, d->optind);
		d->optind++;
		d->optarg = arg.argv[d->optind];
	}
	else
	{
		if (arg.print_error)
			ft_dprintf(FT_STDERR_FD,\
				"%s: option requires an argument -- '%c'\n", arg.argv[0], c);
		d->optopt = c;
		error = arg.colon ? OPT_ERROR_MISS_ARG : OPT_ERROR_DEFAULT;
	}
	return (error);
}

/*
** IF:
**   If argument is optional
** ELSE IF:
**    If Mandatory
**    IF:
**        If there is something after the current index
**    ELSE IF:
**        If there is nothing on the current string but next argument exists
**    ELSE:
**        No argument was provided for the option
*/

int		short_arg(t_getopt_internal_args arg, t_getopt_data *d,\
			int argtype, int c)
{
	int error;

	error = c;
	if (argtype == OPT_ARG_OPTIONAL)
	{
		if (arg.argv[d->optind][d->nextchar + 1])
			d->optarg = &(arg.argv[d->optind][d->nextchar + 1]);
	}
	else if (argtype == OPT_ARG_MANDATORY)
		error = short_arg_ext(arg, d, c);
	argv_mutate(arg, d->optind);
	d->optind++;
	d->nextchar = 0;
	return (error);
}

/*
**  c : Character found in the optstring
**  optstr : contains the output of ft_strchr
**
** !!!hould i really need to send -1 here ???? ** VERIFY ** !!!
**    if (!arg.optstring)
**      return (-1);
**  IF:
**    If option do not exists in the optstring then set the error and stop
**    IF:
**        Option wasn't found in the `optstring`
**    - set the global variables and return appropriately
**
**
**  IF:
**     If some kind of  option is required then manage it
**
**
**  set_getopt_data_short(arg) : No argument is required
*/

int		getopt_internal_short(t_getopt_internal_args arg,\
	t_getopt_data *getopt_data)
{
	char	c;
	char	*optstr;
	int		optarg;

	if (!arg.optstring)
		return (-1);
	c = arg.argv[arg.getopt_data->optind][arg.getopt_data->nextchar];
	optstr = optchr((char *)arg.optstring, c);
	if (!optstr || c == ':' || c == ';')
	{
		if (arg.print_error)
			ft_dprintf(FT_STDERR_FD, "%s: invalid option -- '%c'\n",\
			arg.argv[0], c);
		arg.getopt_data->optopt = c;
		set_getopt_data_short(arg);
		return (OPT_ERROR_DEFAULT);
	}
	optarg = check_optarg(optstr);
	if (optarg != OPT_ARG_NONE)
		return (short_arg(arg, getopt_data, optarg, c));
	set_getopt_data_short(arg);
	return (c);
}
