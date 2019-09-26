/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:01:45 by suddin            #+#    #+#             */
/*   Updated: 2019/09/26 21:02:04 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	set_optarg(char *val)
{
	t_optvar *optvar;

	optvar = get_optvar();
	optvar->optarg = val;
}

void	set_optind(int val)
{
	t_optvar *optvar;

	optvar = get_optvar();
	optvar->optind = val;
}

void	set_opterr(int val)
{
	t_optvar *optvar;

	optvar = get_optvar();
	optvar->opterr = val;
}

void	set_optopt(int val)
{
	t_optvar *optvar;

	optvar = get_optvar();
	optvar->optopt = val;
}
