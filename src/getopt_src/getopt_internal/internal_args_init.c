/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_args_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:11:28 by suddin            #+#    #+#             */
/*   Updated: 2019/09/26 21:11:43 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	internal_args_init(t_getopt_internal_args *internal_arg,\
			t_getopt_arg arg, const char *optstring, const t_option *longopts)
{
	if (!internal_arg)
		return ;
	internal_arg->argc = arg.argc;
	internal_arg->argv = arg.argv;
	internal_arg->optstring = optstring;
	internal_arg->longopts = longopts;
	internal_arg->long_only = 0;
	internal_arg->getopt_data = get_getopt_data();
	internal_arg->opt_treat = OPT_TREAT_MUTATE;
	internal_arg->print_error = internal_arg->getopt_data->opterr;
	internal_arg->colon = FALSE;
	if (internal_arg->optstring && (*(internal_arg->optstring) == '+' ||\
		*(internal_arg->optstring) == '-'))
	{
		internal_arg->opt_treat = *(internal_arg->optstring);
		(internal_arg->optstring)++;
	}
	if (internal_arg->optstring && *(internal_arg->optstring) == ':')
	{
		internal_arg->print_error = OPT_TREAT_NO_PRINT_ERROR;
		internal_arg->colon = TRUE;
		(internal_arg->optstring)++;
	}
}
