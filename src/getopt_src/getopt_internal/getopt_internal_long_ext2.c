/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_internal_long_ext2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:08:23 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 22:08:25 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

void	ambig_set_push(t_ambig_set *ambig_set, int val)
{
	if (!ambig_set)
		return ;
	if (ambig_set->len == ambig_set->max_len)
		ambig_set_realloc(ambig_set);
	ambig_set->index[ambig_set->len] = val;
	ambig_set->len++;
}

int		ambig_set_add(t_ambig_set *ambig_set, const t_option *options,\
				int val, int match_type)
{
	int match;
	int i;

	i = 0;
	match = 0;
	if (match_type == OPT_EXACT_MATCH)
	{
		ambig_set_push(ambig_set, val);
		ambig_set->exact_match = val;
		return (match_type);
	}
	while (i < ambig_set->len)
	{
		if (options[ambig_set->index[i]].has_arg == options[val].has_arg
			&& options[ambig_set->index[i]].flag == options[val].flag
			&& options[ambig_set->index[i]].val == options[val].val)
			match++;
		i++;
	}
	if (match == 0)
		ambig_set_push(ambig_set, val);
	return (match_type);
}

int		search_opt(t_ambig_set *ambig_set, const t_option *options,\
				char *opt)
{
	int i;
	int match;

	i = 0;
	match = OPT_NO_MATCH;
	while (options[i].name)
	{
		match = opt_match((char *)options[i].name, opt);
		if (match == OPT_PARTIAL_MATCH)
			ambig_set_add(ambig_set, options, i, match);
		else if (match == OPT_EXACT_MATCH)
		{
			ambig_set_add(ambig_set, options, i, match);
			return (OPT_EXACT_MATCH);
		}
		i++;
	}
	return (0);
}

void	free_opt_ambig_set(char **opt, t_ambig_set *set)
{
	ft_memdel((void **)opt);
	ft_memdel((void **)&(set->index));
}

void	manage_long_opt_arg(t_getopt_internal_args arg,\
				t_ambig_set *ambig_set, int argument)
{
	int index;

	index = ambig_set->exact_match != OPT_EXACT_MATCH_DEFAULT \
		? ambig_set->exact_match : ambig_set->index[0];
	if (arg.longopts[index].has_arg == REQUIRED_ARGUMENT)
	{
		if (argument != -1)
			arg.getopt_data->optarg =\
				&(arg.argv[arg.getopt_data->optind][argument]);
		else
		{
			arg.getopt_data->optarg = arg.argv[arg.getopt_data->optind + 1];
			set_getopt_data_long(arg);
		}
	}
	else if (arg.longopts[index].has_arg == OPTIONAL_ARGUMENT && argument != -1)
		arg.getopt_data->optarg = &(arg.argv[arg.getopt_data->optind]\
			[argument]);
}
