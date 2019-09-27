/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:31:18 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 18:31:20 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
** internal_args :	Arguments to pass to `getopt_internal`
** optvar :`Globals`
*/

int	ft_getopt(int argc, char *const argv[], const char *optstring)
{
	t_getopt_internal_args	internal_args;
	t_optvar				*optvar;
	t_getopt_data			*getopt_data;
	int						result;
	t_getopt_arg			arg;

	optvar = get_optvar();
	getopt_data = get_getopt_data();
	arg.argc = argc;
	arg.argv = (char **)argv;
	getopt_data->optind = optvar->optind;
	getopt_data->opterr = optvar->opterr;
	internal_args_init(&internal_args, arg, optstring, NULL);
	result = getopt_internal(internal_args, NULL);
	optvar->optind = getopt_data->optind;
	optvar->optarg = getopt_data->optarg;
	optvar->optopt = getopt_data->optopt;
	return (result);
}
