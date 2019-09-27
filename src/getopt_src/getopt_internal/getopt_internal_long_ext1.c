/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_internal_long_ext1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:00:51 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 22:01:53 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
**  *arg = i + 3  ::  3 = '--' + '='
*/

char	*get_option(char *opt, int *arg)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	tmp = ft_strdup(opt);
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		if (tmp[i] == ARG_SEPARATOR)
		{
			*arg = i + 3;
			tmp[i] = 0;
			break ;
		}
		i++;
	}
	return (tmp);
}

/*
**	The following function manages internal variables so we can keep track of
**	where we are now and depending on the situation where we should be for the
**	next call thus changes the optind (option index) and nextchar's value
**
**
**    If we have reached the end of the string then go to the next array
**    element and set the nextchar to 0 so it can start over.
*/

void	set_getopt_data_long(t_getopt_internal_args arg)
{
	argv_mutate(arg, arg.getopt_data->optind);
	arg.getopt_data->optind++;
	arg.getopt_data->nextchar = 0;
}

void	init_ambig_set(t_ambig_set *ambig_set)
{
	if (!ambig_set)
		return ;
	ambig_set->index = (int *)ft_memalloc(sizeof(int) * AMBIG_SET_SIZE);
	ambig_set->len = 0;
	ambig_set->max_len = AMBIG_SET_SIZE;
	ambig_set->exact_match = OPT_EXACT_MATCH_DEFAULT;
	if (!ambig_set->index)
		return ;
}

int		opt_match(char *name, char *opt)
{
	int name_len;
	int opt_len;
	int i;

	if (!name || !opt)
		return (0);
	name_len = ft_strlen(name);
	opt_len = ft_strlen(opt);
	if (name_len == 0 && opt_len == 0)
		return (OPT_EXACT_MATCH);
	else if (opt == 0 && name_len > 0)
		return (OPT_PARTIAL_MATCH);
	i = 0;
	while (name[i] && opt[i])
	{
		if (name[i] != opt[i])
			break ;
		i++;
	}
	if (i == name_len && i == opt_len)
		return (OPT_EXACT_MATCH);
	else if (i == opt_len)
		return (OPT_PARTIAL_MATCH);
	else
		return (OPT_NO_MATCH);
}

void	ambig_set_realloc(t_ambig_set *ambig_set)
{
	int *index;
	int max_len;
	int i;

	if (!ambig_set)
		return ;
	max_len = ambig_set->max_len + AMBIG_SET_SIZE;
	i = 0;
	index = (int *)ft_memalloc(sizeof(int) * max_len);
	if (!index)
		return ;
	while (ambig_set->max_len && i < ambig_set->len)
	{
		index[i] = ambig_set->index[i];
		i++;
	}
	if (ambig_set->index)
		ft_memdel((void **)&(ambig_set->index));
	ambig_set->index = index;
	ambig_set->max_len = max_len;
}
