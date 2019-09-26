#include "ft_getopt.h"
#include <stdio.h>

char *get_option(char *opt, int *arg)
{
	char *tmp;
	int i;

	tmp = NULL;
	i = 0;
	tmp = ft_strdup(opt);
	if(!tmp)
		return (NULL);

	while(tmp[i])
	{
		if(tmp[i] == ARG_SEPARATOR)
		{
			*arg = i + 3; /* 3 = '--' + '=' */
			tmp[i] = 0;
			break;
		}
		i++;
	}
	return(tmp);
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

void set_getopt_data_long(t_getopt_internal_args arg)
{
	argv_mutate(arg, arg.getopt_data->optind);
	arg.getopt_data->optind++;
	arg.getopt_data->nextchar = 0;
}

void init_ambig_set(t_ambig_set *ambig_set)
{
	if(!ambig_set)
		return ;
	ambig_set->index = (int *) ft_memalloc(sizeof(int) * AMBIG_SET_SIZE);
	ambig_set->len = 0;
	ambig_set->max_len = AMBIG_SET_SIZE;
	ambig_set->exact_match = OPT_EXACT_MATCH_DEFAULT;
	if(!ambig_set->index)
		return ;
}

int opt_match(char *name, char *opt)
{
	int name_len;
	int opt_len;
	int i;

	if (!name || !opt)
		return (0);
	name_len = ft_strlen(name);
	opt_len = ft_strlen(opt);
	if(name_len == 0 && opt_len == 0)
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
		return(OPT_NO_MATCH);
}


void ambig_set_realloc(t_ambig_set *ambig_set)
{
	int *index;
	int max_len;
	int i;

	if (!ambig_set)
		return ;
	max_len = ambig_set->max_len + AMBIG_SET_SIZE;
	i = 0;
	index = (int *) ft_memalloc(sizeof(int) * max_len);
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

void ambig_set_push(t_ambig_set *ambig_set, int val)
{
	if (!ambig_set)
		return ;
	if (ambig_set->len == ambig_set->max_len)
		ambig_set_realloc(ambig_set);
	ambig_set->index[ambig_set->len] = val;
	ambig_set->len++;

}

int ambig_set_add(t_ambig_set *ambig_set, const t_option *options, int val,\
	int match_type)
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


int search_opt(t_ambig_set *ambig_set, const t_option *options, char *opt)
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
			return(OPT_EXACT_MATCH);
		}
		i++;
	}
	return (0);
}

void free_opt_ambig_set(char **opt, t_ambig_set *set)
{
	ft_memdel((void **)opt);
	ft_memdel((void **)&(set->index));
}

void manage_long_opt_arg(t_getopt_internal_args arg, t_ambig_set *ambig_set, int argument)
{
	int index;

	index = ambig_set->exact_match != OPT_EXACT_MATCH_DEFAULT \
		? ambig_set->exact_match : ambig_set->index[0];
	if (arg.longopts[index].has_arg == REQUIRED_ARGUMENT)
	{
		if (argument != -1)
			arg.getopt_data->optarg = &(arg.argv[arg.getopt_data->optind][argument]);
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

int longopt_err(t_getopt_internal_args arg, char *argv,\
	const char *opt, int err)
{
	if (err == 1)
	{
		if (arg.print_error)
			ft_dprintf( FT_STDERR_FD, "%s: option '--%s' doesn't allow an argument\n",\
			argv, opt);
		set_getopt_data_long(arg);
		return (OPT_ERROR_DEFAULT);
	}
	else if (err == 2)
	{
		if (arg.print_error)
			ft_dprintf( FT_STDERR_FD, "%s: option '--%s' requires an argument\n",\
			argv, opt);
		set_getopt_data_long(arg);
		return (arg.colon ? OPT_ERROR_MISS_ARG : OPT_ERROR_DEFAULT);
	}
	return (OPT_ERROR_DEFAULT);
}

int manage_long_opt(t_getopt_internal_args arg, int *longindex,\
	t_ambig_set *ambig_set, int argument)
{
	int index;

	index = ambig_set->exact_match != OPT_EXACT_MATCH_DEFAULT \
		? ambig_set->exact_match : ambig_set->index[0];
	/* Manages errors */

	/* Need no argument but has one argument */
	if (arg.longopts[index].has_arg == NO_ARGUMENT && argument != -1)
		return(longopt_err(arg, arg.argv[0], arg.longopts[index].name, 1));
	/* Requires an argument but has none */
	else if (arg.longopts[index].has_arg == REQUIRED_ARGUMENT \
			&& (argument == -1 && arg.getopt_data->optind + 1 == arg.argc))
		return (longopt_err(arg, arg.argv[0], arg.longopts[index].name, 2));


	if (longindex)
		*longindex = index;
	if (arg.longopts[index].has_arg != NO_ARGUMENT)
		manage_long_opt_arg(arg, ambig_set, argument);

	set_getopt_data_long(arg);
	return (arg.longopts[index].flag ? 0 : arg.longopts[index].val);
}

int manage_long_opt_ambig(t_getopt_internal_args arg, t_ambig_set ambig_set)
{
	int i;

	i = 0;
	if (arg.print_error)
	{
		ft_dprintf( FT_STDERR_FD,  "%s: option '%s' is ambiguous; possibilities:",\
		arg.argv[0], arg.argv[arg.getopt_data->optind]);
		while (i < ambig_set.len)
		{
			ft_dprintf( FT_STDERR_FD, " '--%s'", arg.longopts[ambig_set.index[i]].name);
			i++;
		}
		ft_dprintf( FT_STDERR_FD, "\n");
	}
	set_getopt_data_long(arg);
	return (OPT_ERROR_DEFAULT);
}

int getopt_internal_long(t_getopt_internal_args arg, t_getopt_data *getopt_data, int *longindex)
{
	char		*opt; // must free this variable
	int			argument;
	t_ambig_set	ambig_set;
	int			ret;

	opt = NULL;
	argument = -1;
	opt = get_option(&(arg.argv[getopt_data->optind][getopt_data->nextchar]), &argument);
	init_ambig_set(&ambig_set);
	search_opt(&ambig_set, arg.longopts, opt);
	if (ambig_set.len == 0)
	{
		if (arg.print_error)
			ft_dprintf( FT_STDERR_FD, "%s: unrecognized option '%s'\n", arg.argv[0], arg.argv[getopt_data->optind]);
		free_opt_ambig_set(&opt, &ambig_set);
		set_getopt_data_long(arg);
		getopt_data->optopt = 0;
		return (OPT_ERROR_DEFAULT);
	}
	else if (ambig_set.exact_match != OPT_EXACT_MATCH_DEFAULT ||   ambig_set.len == 1)
		ret = manage_long_opt(arg, longindex, &ambig_set, argument);
	else
		ret = manage_long_opt_ambig(arg, ambig_set);
	free_opt_ambig_set(&opt, &ambig_set);
	return (ret);
}
