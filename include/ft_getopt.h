#ifndef GETOPT_H
# define GETOPT_H

# include "libft.h"
# include "ft_printf.h"

# define OPTIND 					0
# define OPTERR 					1
# define OPTOPT 					2
# define OPTARG 					3


/*
   The following defines are used as values of the lement `has_arg` of the
   structure `struct s_option`. The followiing defines are in small case
   in the original library
   (https://github.com/lattera/glibc/blob/master/posix/bits/getopt_ext.h#L62-L64)
   in 42 the defines must be declared in `capital letters`
*/

# define NO_ARGUMENT				0
# define REQUIRED_ARGUMENT			1
# define OPTIONAL_ARGUMENT			2

# define GETOPT_INITIALIZED			1
# define GETOPT_ERROR_SHOW			1

/* Option types */
# define OPT_TYPE_NONE				0
# define OPT_TYPE_ARG				1 /* Set arguments as parameters if the `-` is present in `optstring` */
# define OPT_TYPE_SHORT				2
# define OPT_TYPE_LONG				3
# define OPT_TYPE_END				4
# define OPT_TYPE_ERROR				-1

# define GETOPT_END					-1

#ifndef NULL
# define NULL ((void *)0)
#endif

#ifndef TRUE
# define TRUE						1
#endif

#ifndef FALSE
# define FALSE						0
#endif

# define OPT_TREAT_NO_PRINT_ERROR	0
# define OPT_TREAT_PRINT_ERROR		1
# define OPT_TREAT_POSIXLY_CORRECT	'+' /* If any non option is found then stop */
# define OPT_TREAT_NON_OPT_ARG		'-'	/* If a non option is found treat it as an option argument */
# define OPT_TREAT_MUTATE			2	/* move all non option argument to the end of array */

/* Getopt error returns */
# define OPT_ERROR_DEFAULT			'?'
# define OPT_ERROR_MISS_ARG			':' /*
										   If the `:` option is passed to optstring
										   then in case of missing argument the following
										   character will be returned.
										   */


# define OPT_ARG_NONE				0 /* No arhuments are required */
# define OPT_ARG_MANDATORY			1 /* An argument is required */
# define OPT_ARG_OPTIONAL			2 /* An optional argument is required */


# define ARG_SEPARATOR				'='

# define AMBIG_SET_SIZE				50

# define OPT_NO_MATCH				0
# define OPT_PARTIAL_MATCH			1
# define OPT_EXACT_MATCH			2
# define OPT_EXACT_MATCH_DEFAULT	-1


/*
   The following structured is used to pass iformation about long options
   */

typedef struct	s_option
{
	const char	*name;	/* The long option name */
	int			has_arg;
	int			*flag; 	/*
						   If null then returns value,
						   else saven the value of val
						   */

	int			val;	/*
						   If f*lag is null then returns the value of val else
						   saves the value of val in *flag
						   */
}				t_option;



/*
   The following structure is used to store the bariables which are global
   in the system `getopt`. As in some projects at 42 it is forbidden to use
   global variables so we use a structure that will be declared as a `static`
   and `Emulate` global variables.
   */

typedef struct	s_optvar
{
	int			initialized;/* if true then the structure was initialized */

	char		*optarg;	/* store the argument index */
	int 		optind;		/* contain the current index of argv that is being parsed */
	int			opterr;		/* indicates whater an error message should be shown (1) or not (0) */
	int			optopt;		/* Containes the erroneous option */
}				t_optvar;



/*
   The following structure is used to reduce the length of parameters where
   you pute `argc` and `argv` as parameters.
   */

typedef struct	s_getopt_arg
{
	int		argc;
	char	**argv;
}				t_getopt_arg;



/* This structure contain an internal copy of treated data */

typedef struct	s_getopt_data
{
	int		initialized;/* This is set to 1 if the structure is initialised else 0 */
	char	*optarg;	/* Points to an argument index */
	int		optind;		/* Contain treatable index of argv */
	int		opterr;		/* Indicate of an error repord must be printed on stderr */
	int		optopt;		/* The argument that was not specified in option string */
	int		nextchar;	/* Saves the next character of short argument (of argv) befor return */

	// int		finished;	/* Indicate if getopt has finished treating arguments (0: default, 1 : finished) */

	int		last_optind;/* Saves the index of the last valide */

}				t_getopt_data;

typedef struct	s_ambig_set
{
	int *index;		/* Saves the indexes of options of `t_option` that matches current option */
	int len;		/* Contain the lenth of valide values */
	int max_len;	/* Contained the max allocated length for current index */
	int exact_match;/* If there was an exact match found then the value is non negatif */
}				t_ambig_set;

/*
   The following structure is used to passe arguments to getopt_internal(...)
   function, as in 42 only 4 arguments are the most argument that we can pass
   so this `hack` is used.
   */

typedef struct	s_getopt_internal_args
{
	int				argc;
	char			**argv;
	const char		*optstring;
	const t_option	*longopts;
	int				long_only;
	t_getopt_data	*getopt_data;
	// int				posixly_correct;

	int				print_error; /* used with `optstring` activated if `:` present */
	int				colon;		/* used with `optstring` activated if `:` present only */
	int				opt_treat;  /* used with `optstring` activated if `-` or `+` present */

}				t_getopt_internal_args;



t_getopt_data	*get_getopt_data();
int				ft_getopt(int argc, char * const argv[], const char *optstring);
int				ft_getopt_long(t_getopt_arg arg, const char *optstring, const t_option *longopts, int *longindex);
int				ft_getopt_long_only(t_getopt_arg arg, const char *optstring, const t_option *longopts, int *longindex);

/* optvar related */
t_optvar		*get_optvar();
/* All getters */
char			**get_optarg();
int				*get_optind();
int				*get_opterr();
int				*get_optopt();
/* All setters */
void			set_optarg(char *val);
void			set_optind(int val);
void			set_opterr(int val);
void			set_optopt(int val);



/* Main generic function used by getopt* */
int				getopt_internal(t_getopt_internal_args arg, int *longindex);
int				getopt_internal_long(t_getopt_internal_args arg, t_getopt_data *getopt_data, int *longindex);
int				getopt_internal_short(t_getopt_internal_args arg, t_getopt_data *getopt_data);


int				set_next_opt(t_getopt_internal_args int_arg, int argc, char **argv); // TODO: delete this one
void			argv_mutate(t_getopt_internal_args arg, int index); // <---
int				option_type(char *opt);
void			internal_args_init(t_getopt_internal_args *internal_arg,\
		t_getopt_arg arg, const char *optstring,  const t_option *longopts);
int				getopt_end(t_getopt_internal_args arg);

#endif
