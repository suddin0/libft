/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_internal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:36:34 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 20:45:18 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

#include <stdio.h>

/*
** The following function is an extention of `getopt_internal` as it surpasses
** the norm of 25 line max functions.
**
** In this function we return -99 to indicate that non of the condtion passed.
** thus continue the other conditions in the `mother function`
*/

inline static int	getopt_internal_extra(t_getopt_internal_args arg,\
						int *longindex)
{
	t_getopt_data			*getopt_data;
	int						opt_type;

	getopt_data = get_getopt_data();
	getopt_data->optarg = NULL;
	opt_type = set_next_opt(arg, arg.argc, arg.argv);
	if (opt_type == OPT_TYPE_ERROR || opt_type == OPT_TYPE_END)
		return (getopt_end(arg, opt_type));
	else if (opt_type == OPT_TYPE_ARG)
		return (opt_type);
	else if (opt_type == OPT_TYPE_SHORT ||\
			(opt_type == OPT_TYPE_LONG && arg.longopts == NULL))
	{
		getopt_data->nextchar++;
		return (getopt_internal_short(arg, getopt_data));
	}
	else if (opt_type == OPT_TYPE_LONG)
	{
		getopt_data->nextchar += 2;
		return (getopt_internal_long(arg, getopt_data, longindex));
	}
	return (-99);
}

/*
** first IF:
**      If there are no arguments then stop.
**
**      If for some reason we surpassed the number of arguments given.
**
**      If arguments are passed and the special `--` option was encountered
**      or for some reasion the `t_getopt_data.finished` is active then stop.
**
**
**  second IF
**      If we are in the begining of an argument then check if it is a long or
**      short option otherwise by default it is a short option.
**
**          get the next option if found else stop
**
**          midle ELSE IF:
**                jump the first `-` character
*/

int					getopt_internal(t_getopt_internal_args arg, int *longindex)
{
	t_getopt_data			*getopt_data;
	int						ret;

	ret = 0;
	getopt_data = get_getopt_data();
	getopt_data->optarg = NULL;
	if (arg.argc < 1 || getopt_data->optind >= arg.argc)
		return (getopt_end(arg, 0));
	if (getopt_data->nextchar == 0)
	{
		ret = getopt_internal_extra(arg, longindex);
		if (ret != -99)
			return (ret);
	}
	else
		return (getopt_internal_short(arg, getopt_data));
	return (getopt_end(arg, 0));
}
