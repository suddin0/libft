/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:32:27 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 18:32:28 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

static void		getopt_data_init(t_getopt_data *getopt_data)
{
	if (!getopt_data)
		return ;
	getopt_data->initialized = GETOPT_INITIALIZED;
	getopt_data->optarg = NULL;
	getopt_data->optind = 1;
	getopt_data->opterr = 1;
	getopt_data->optopt = 0;
	getopt_data->nextchar = 0;
	getopt_data->last_optind = 1;
}

t_getopt_data	*get_getopt_data(void)
{
	static t_getopt_data getopt_data;

	if (!getopt_data.initialized)
		getopt_data_init(&getopt_data);
	return (&getopt_data);
}
