/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:32:56 by suddin            #+#    #+#             */
/*   Updated: 2019/09/30 22:26:57 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

int	getopt_end(t_getopt_internal_args arg, int opt_type)
{
	if (arg.opt_treat == OPT_TREAT_MUTATE)
		arg.getopt_data->optind = arg.getopt_data->last_optind;
	else if (arg.opt_treat == OPT_TREAT_POSIXLY_CORRECT)
	{
		if (opt_type == OPT_TYPE_END)
			arg.getopt_data->optind++;
	}
	return (GETOPT_END);
}
