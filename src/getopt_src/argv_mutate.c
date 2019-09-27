/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_mutate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:59:36 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 17:03:08 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static void	swap_index(int argc, char **argv, int a, int b)
{
	char *tmp;

	if (a < 0 || b < 0 || a == b || a >= argc || b >= argc)
		return ;
	tmp = argv[a];
	argv[a] = argv[b];
	argv[b] = tmp;
}

void		argv_mutate(t_getopt_internal_args arg, int index)
{
	t_getopt_data *data;

	data = arg.getopt_data;
	if (!arg.argv || index >= arg.argc || arg.opt_treat != OPT_TREAT_MUTATE)
		return ;
	data->last_optind++;
	while (index > 0 && index > data->last_optind)
	{
		swap_index(arg.argc, arg.argv, index, index - 1);
		index--;
	}
}
