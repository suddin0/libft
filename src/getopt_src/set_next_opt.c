/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_next_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:44:33 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 18:44:55 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
** Set up getopt_data variables
*/

static int	set_non_opt_arg(t_getopt_internal_args int_arg, int index)
{
	int_arg.getopt_data->optarg = int_arg.argv[index];
	int_arg.getopt_data->optind++;
	int_arg.getopt_data->nextchar = 0;
	return (OPT_TYPE_ARG);
}

/*
** return(GETOPT_END) : Set up getopt_data variables
**
** set_non_opt_arg(...) : Set up getopt_data variables
**
**
** if(opt_type == OPT_TYPE_END) : If found `--`
** {
** 	--> Set up getopt_data variables
** 	argv_mutate(int_arg, int_arg.getopt_data->optind);
** 	return(GETOPT_END);
** }
*/

int			set_next_opt(t_getopt_internal_args int_arg, int argc, char **argv)
{
	int opt_type;

	if (!argv || int_arg.getopt_data->optind >= argc)
		return (OPT_TYPE_ERROR);
	opt_type = OPT_TYPE_ERROR;
	while (int_arg.getopt_data->optind < argc)
	{
		opt_type = option_type(argv[int_arg.getopt_data->optind]);
		if (int_arg.opt_treat == OPT_TREAT_POSIXLY_CORRECT\
			&& opt_type == OPT_TYPE_NONE)
			return (GETOPT_END);
		else if (int_arg.opt_treat == OPT_TREAT_NON_OPT_ARG\
			&& opt_type == OPT_TYPE_NONE)
			return (set_non_opt_arg(int_arg, int_arg.getopt_data->optind));
		if (opt_type == OPT_TYPE_END)
		{
			argv_mutate(int_arg, int_arg.getopt_data->optind);
			return (OPT_TYPE_END);
		}
		else if (opt_type != OPT_TYPE_NONE)
			return (opt_type);
		int_arg.getopt_data->optind++;
	}
	return (OPT_TYPE_ERROR);
}
