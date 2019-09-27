/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:59:27 by suddin            #+#    #+#             */
/*   Updated: 2019/09/26 20:59:32 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

char	**get_optarg(void)
{
	t_optvar *optvar;

	optvar = get_optvar();
	return (&(optvar->optarg));
}

int		*get_optind(void)
{
	t_optvar *optvar;

	optvar = get_optvar();
	return (&(optvar->optind));
}

int		*get_opterr(void)
{
	t_optvar *optvar;

	optvar = get_optvar();
	return (&(optvar->opterr));
}

int		*get_optopt(void)
{
	t_optvar *optvar;

	optvar = get_optvar();
	return (&(optvar->optopt));
}
