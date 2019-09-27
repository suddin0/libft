/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_internal_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:13:09 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 21:26:44 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include <stdio.h>

static int	longopt_err(t_getopt_internal_args arg, char *argv,\
	const char *opt, int err)
{
	if (err == 1)
	{
		if (arg.print_error)
			ft_dprintf(FT_STDERR_FD,\
				"%s: option '--%s' doesn't allow an argument\n", argv, opt);
		set_getopt_data_long(arg);
		return (OPT_ERROR_DEFAULT);
	}
	else if (err == 2)
	{
		if (arg.print_error)
			ft_dprintf(FT_STDERR_FD,\
				"%s: option '--%s' requires an argument\n", argv, opt);
		set_getopt_data_long(arg);
		return (arg.colon ? OPT_ERROR_MISS_ARG : OPT_ERROR_DEFAULT);
	}
	return (OPT_ERROR_DEFAULT);
}

/*
**  index = ambig_set->exact_match != OPT_EXACT_MATCH_DEFAULT \
**  	? ambig_set->exact_match : ambig_set->index[0];
**  -- Manages errors --
**
**  -- Need no argument but has one argument --
**  if (arg.longopts[index].has_arg == NO_ARGUMENT && argument != -1)
**  	return(longopt_err(arg, arg.argv[0], arg.longopts[index].name, 1));
**  -- Requires an argument but has none --
**  else if (arg.longopts[index].has_arg == REQUIRED_ARGUMENT \
**  		&& (argument == -1 && arg.getopt_data->optind + 1 == arg.argc))
**  	return (longopt_err(arg, arg.argv[0], arg.longopts[index].name, 2));
*/

static int	manage_long_opt(t_getopt_internal_args arg, int *longindex,\
	t_ambig_set *ambig_set, int argument)
{
	int index;

	index = ambig_set->exact_match != OPT_EXACT_MATCH_DEFAULT \
		? ambig_set->exact_match : ambig_set->index[0];
	if (arg.longopts[index].has_arg == NO_ARGUMENT && argument != -1)
		return (longopt_err(arg, arg.argv[0], arg.longopts[index].name, 1));
	else if (arg.longopts[index].has_arg == REQUIRED_ARGUMENT \
			&& (argument == -1 && arg.getopt_data->optind + 1 == arg.argc))
		return (longopt_err(arg, arg.argv[0], arg.longopts[index].name, 2));
	if (longindex)
		*longindex = index;
	if (arg.longopts[index].has_arg != NO_ARGUMENT)
		manage_long_opt_arg(arg, ambig_set, argument);
	set_getopt_data_long(arg);
	return (arg.longopts[index].flag ? 0 : arg.longopts[index].val);
}

static int	manage_long_opt_ambig(t_getopt_internal_args arg,\
				t_ambig_set ambig_set)
{
	int i;

	i = 0;
	if (arg.print_error)
	{
		ft_dprintf(FT_STDERR_FD,
				"%s: option '%s' is ambiguous; possibilities:",\
		arg.argv[0], arg.argv[arg.getopt_data->optind]);
		while (i < ambig_set.len)
		{
			ft_dprintf(FT_STDERR_FD, " '--%s'",
					arg.longopts[ambig_set.index[i]].name);
			i++;
		}
		ft_dprintf(FT_STDERR_FD, "\n");
	}
	set_getopt_data_long(arg);
	return (OPT_ERROR_DEFAULT);
}

/*
**  The following function is an extention of `getopt_internal_long`. It exists
**  to respect the 42 norm of 25 line max function.
*/

void		getopt_internal_long_ext(t_getopt_internal_args arg,\
	t_getopt_data *getopt_data, char **opt, t_ambig_set *ambig_set)
{
	if (arg.print_error)
		ft_dprintf(FT_STDERR_FD, "%s: unrecognized option '%s'\n",\
				arg.argv[0], arg.argv[getopt_data->optind]);
	free_opt_ambig_set(opt, ambig_set);
	set_getopt_data_long(arg);
	getopt_data->optopt = 0;
}

/*
**  *opt : must free this variable
*/

int			getopt_internal_long(t_getopt_internal_args arg,\
			t_getopt_data *getopt_data, int *longindex)
{
	char		*opt;
	int			argument;
	t_ambig_set	ambig_set;
	int			ret;

	opt = NULL;
	argument = -1;
	opt = get_option(&(arg.argv[getopt_data->optind][getopt_data->nextchar]),\
			&argument);
	init_ambig_set(&ambig_set);
	search_opt(&ambig_set, arg.longopts, opt);
	if (ambig_set.len == 0)
	{
		getopt_internal_long_ext(arg, getopt_data, &opt, &ambig_set);
		return (OPT_ERROR_DEFAULT);
	}
	else if (ambig_set.exact_match != OPT_EXACT_MATCH_DEFAULT\
				|| ambig_set.len == 1)
		ret = manage_long_opt(arg, longindex, &ambig_set, argument);
	else
		ret = manage_long_opt_ambig(arg, ambig_set);
	free_opt_ambig_set(&opt, &ambig_set);
	return (ret);
}
