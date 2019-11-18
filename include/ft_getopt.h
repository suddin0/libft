/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:17:48 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:31:33 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

# define OPTIND 					0
# define OPTERR 					1
# define OPTOPT 					2
# define OPTARG 					3

/*
**  The following defines are used as values of the lement `has_arg` of the
**  structure `struct s_option`. The followiing defines are in small case
**  in the original library
**(https://github.com/lattera/glibc/blob/master/posix/bits/getopt_ext.h#L62-L64)
**  in 42 the defines must be declared in `capital letters`
*/

# define NO_ARGUMENT				0
# define REQUIRED_ARGUMENT			1
# define OPTIONAL_ARGUMENT			2

# define GETOPT_INITIALIZED			1
# define GETOPT_ERROR_SHOW			1

/*
** Option types
*/
# define OPT_TYPE_NONE				0

/*
** Set arguments as parameters if the `-` is present in `optstring`
*/
# define OPT_TYPE_ARG				1
# define OPT_TYPE_SHORT				2
# define OPT_TYPE_LONG				3
# define OPT_TYPE_END				4
# define OPT_TYPE_ERROR				-1

# define GETOPT_END					-1

# ifndef NULL
#  define NULL ((void *)0)
# endif

# ifndef TRUE
#  define TRUE						1
# endif

# ifndef FALSE
#  define FALSE						0
# endif

# define OPT_TREAT_NO_PRINT_ERROR	0
# define OPT_TREAT_PRINT_ERROR		1

/*
** If any non option is found then stop
*/

# define OPT_TREAT_POSIXLY_CORRECT	'+'

/*
** If a non option is found treat it as an option argument
*/

# define OPT_TREAT_NON_OPT_ARG		'-'

/*
** move all non option argument to the end of array
*/

# define OPT_TREAT_MUTATE			2

/*
** Getopt error returns
*/

# define OPT_ERROR_DEFAULT			'?'

/*
** If the `:` option is passed to optstring
** then in case of missing argument the following
** character will be returned.
*/

# define OPT_ERROR_MISS_ARG			':'

/*
** No arhuments are required
*/

# define OPT_ARG_NONE				0

/*
** An argument is required
*/

# define OPT_ARG_MANDATORY			1

/*
** An optional argument is required
*/

# define OPT_ARG_OPTIONAL			2

# define ARG_SEPARATOR				'='

# define AMBIG_SET_SIZE				50

# define OPT_NO_MATCH				0
# define OPT_PARTIAL_MATCH			1
# define OPT_EXACT_MATCH			2
# define OPT_EXACT_MATCH_DEFAULT	-1

/*
**  The following structured is used to pass iformation about long options
**
**  name : The long option name
**  has_arg
**  flag : If null then returns value, else saven the value of val
**
**
**  val :	If flag is null then returns the value of val else saves the value
**			of val in *flag
*/

typedef struct	s_option
{
	const char	*name;
	int			has_arg;
	int			*flag;
	int			val;
}				t_option;

/*
**  The following structure is used to store the bariables which are global
**  in the system `getopt`. As in some projects at 42 it is forbidden to use
**  global variables so we use a structure that will be declared as a `static`
**  and `Emulate` global variables.
**
**
** initialized : if true then the structure was initialized
**
** optarg : store the argument index
** optind : contain the current index of argv that is being parsed
** opterr : indicates whater an error message should be shown (1) or not (0)
** optopt : Containes the erroneous option
*/

typedef struct	s_optvar
{
	int		initialized;
	char	*optarg;
	int		optind;
	int		opterr;
	int		optopt;
}				t_optvar;

/*
** The following structure is used to reduce the length of parameters where
** you pute `argc` and `argv` as parameters.
*/

typedef struct	s_getopt_arg
{
	int		argc;
	char	**argv;
}				t_getopt_arg;

/*
** This structure contain an internal copy of treated data
**
** initialized	: This is set to 1 if the structure is initialised else 0
** optarg		: Points to an argument index
** optind		: Contain treatable index of argv
** opterr		: Indicate of an error repord must be printed on stderr
** optopt		: The argument that was not specified in option string
** nextchar	: Saves the next character of short argument (of argv) befor return
** last_optind : Saves the index of the last valide
*/

typedef struct	s_getopt_data
{
	int		initialized;
	char	*optarg;
	int		optind;
	int		opterr;
	int		optopt;
	int		nextchar;
	int		last_optind;
}				t_getopt_data;

/*
** index: Saves the indexes of options of `t_option` that matches current option
** len :  Contain the lenth of valide values
** max_len :  Contained the max allocated length for current index
** exact_match : If there was an exact match found then the value is non negatif
*/

typedef struct	s_ambig_set
{
	int *index;
	int len;
	int max_len;
	int exact_match;
}				t_ambig_set;

/*
** The following structure is used to passe arguments to getopt_internal(...)
** function, as in 42 only 4 arguments are the most argument that we can pass
** so this `hack` is used.
**
** argc :
** argv :
** optstring :
** t_option	*longopts :
** long_only :
** *getopt_data :
**
** print_error	: used with `optstring` activated if `:` present
** colon		: used with `optstring` activated if `:` present only
** opt_treat	: used with `optstring` activated if `-` or `+` present
*/

typedef struct	s_getopt_internal_args
{
	int				argc;
	char			**argv;
	const char		*optstring;
	const t_option	*longopts;
	int				long_only;
	t_getopt_data	*getopt_data;
	int				print_error;
	int				colon;
	int				opt_treat;
}				t_getopt_internal_args;

t_getopt_data	*get_getopt_data();
int				ft_getopt(int argc, char *const argv[], const char *optstring);
int				ft_getopt_long(t_getopt_arg arg, const char *optstring,\
					const t_option *longopts, int *longindex);
int				ft_getopt_long_only(t_getopt_arg arg, const char *optstring,\
					const t_option *longopts, int *longindex);

/*
** optvar related
*/

t_optvar		*get_optvar();

/*
** All getters
*/

char			**get_optarg();
int				*get_optind();
int				*get_opterr();
int				*get_optopt();

/*
** All setters
*/

void			set_optarg(char *val);
void			set_optind(int val);
void			set_opterr(int val);
void			set_optopt(int val);

/*
**  Extended functions for `getopt_internal_long` (because of 42 norm)
**
**  Of file `getopt_internal_long_ext1.c`
*/

char			*get_option(char *opt, int *arg);
void			set_getopt_data_long(t_getopt_internal_args arg);
void			init_ambig_set(t_ambig_set *ambig_set);
int				opt_match(char *name, char *opt);
void			ambig_set_realloc(t_ambig_set *ambig_set);

/*
**  Extended functions for `getopt_internal_long` (because of 42 norm)
**
**  Of file `getopt_internal_long_ext2.c`
*/

void			ambig_set_push(t_ambig_set *ambig_set, int val);
int				ambig_set_add(t_ambig_set *ambig_set, const t_option *options,\
					int val, int match_type);
int				search_opt(t_ambig_set *ambig_set, const t_option *options,\
						char *opt);
void			free_opt_ambig_set(char **opt, t_ambig_set *set);
void			manage_long_opt_arg(t_getopt_internal_args arg,\
					t_ambig_set *ambig_set, int argument);

/*
** Main generic function used by getopt*
*/

char			*optchr(char *str, char c);
int				getopt_internal(t_getopt_internal_args arg, int *longindex);
int				getopt_internal_long(t_getopt_internal_args arg,\
					t_getopt_data *getopt_data, int *longindex);
int				getopt_internal_short(t_getopt_internal_args arg,\
					t_getopt_data *getopt_data);
/*
**  // TODO: delete this one ??? WTF???
*/

int				set_next_opt(t_getopt_internal_args int_arg, int argc,\
					char **argv);
void			argv_mutate(t_getopt_internal_args arg, int index);
int				option_type(char *opt);
void			internal_args_init(t_getopt_internal_args *internal_arg,\
					t_getopt_arg arg, const char *optstring,\
					const t_option *longopts);
int				getopt_end(t_getopt_internal_args arg, int opt_type);

#endif
