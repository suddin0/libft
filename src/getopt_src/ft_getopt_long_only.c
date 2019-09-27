/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt_long_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:29:08 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 18:29:15 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
** internal_args :	Arguments to pass to `getopt_internal`
** optvar :`Globals`
*/

int	ft_getopt_long_only(t_getopt_arg arg, const char *optstring,\
	const t_option *longopts, int *longindex)
{
	t_getopt_internal_args	internal_args;
	t_optvar				*optvar;
	t_getopt_data			*getopt_data;
	int						result;

	optvar = get_optvar();
	getopt_data = get_getopt_data();
	getopt_data->optind = optvar->optind;
	getopt_data->opterr = optvar->opterr;
	internal_args_init(&internal_args, arg, optstring, longopts);
	result = getopt_internal(internal_args, longindex);
	optvar->optind = getopt_data->optind;
	optvar->optarg = getopt_data->optarg;
	optvar->optopt = getopt_data->optopt;
	return (result);
}
