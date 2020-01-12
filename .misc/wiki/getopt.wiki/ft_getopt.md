# ft_getopt

There are 3 function provided by the standard library to parse command line arguments:

| | Function names|
|-|--------------|
|1 | getopt |
|2 | getopt_long|
|3 | getopt_long_only |

The prototype of those function looks as following:
```c
int getopt(int argc, char * const argv[], const char *optstring);

int getopt_long_only(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);
```

**ft_getopt** privides the same 3 functions:

| | Function names|
|-|--------------|
|1 | ft_getopt |
|2 | ft_getopt_long|
|3 | ft_getopt_long_only |

The prototype of those function looks as following:
```c
int ft_getopt(int argc, char * const argv[], const char *optstring);

int ft_getopt_long(t_getopt_arg arg, const char *optstring, const t_option *longopts, int *longindex);

int ft_getopt_long_only(t_getopt_arg arg, const char *optstring, const t_option *longopts, int *longindex);
```

Both of them (functions from the standard library and from **ft_getopt**) works more or less the same way but the do have some significant differences.

# Differences

## Global variables
There are some differences for example the global variables `optarg`, `optind`, `opterr` and `optopt` are not implemented globally, because in many **42** projects you are not allowed to use `global variables` and that could be a problem to use this library.

The solution for this problem was to use `static variables` to simulate `global variables`.
instead of using a series of variable we use a structure called [t_optvar]() :
```c
typedef struct	s_optvar
{
	int	initialized;	/* if true then the structure was initialized */
	char	*optarg;	/* store the argument index */
	int 	optind;		/* contain the current index of argv that is being parsed */
	int	opterr;		/* indicates whater an error message should be shown (1) or not (0) */
	int	optopt;		/* Containes the erroneous option */
}		t_optvar;
```
in this structure we can find the same type of variables as the standard library provide for **getopt**.

> Note: The variable **`initialized`** is used internally to indicate if the structure is already initialized.

The reason for using a structure is to ease the use of variables for the user, as there aren't many option for the user to manipulate those variable but to have access to their memory address and manipulate them and to do this one might have to declare more then one variable and in 42 there are a limit of variable that we can declare so a structure helps declare less variable.

A series of functions are implemented to manipulate the structure and variables, they are implemented as [getter](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)#General_definition)  and [setter](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)#General_definition):

```c
t_optvar	*get_optvar();		/* get the whole  t_optvar structure */

/* All getters */
char		**get_optarg();		/* Get the pointer of the variable optarg */
int		*get_optind();		/* Get the pointer of the variable optind */
int		*get_opterr();		/* Get the pointer of the variable opterr */
int		*get_optopt();		/* Get the pointer of the variable optopt */

/* All setters */
void		set_optarg(char *val); 	/* set the value to optarg */
void		set_optind(int val);	/* set the value to optind */
void		set_opterr(int val);	/* set the value to opterr */
void		set_optopt(int val);	/* set the value to optopt */
```

## Function parameters.
You might also notice that the prototype of `getopt_long` and `getopt_long_only` are not the same for `ft_getopt_long` and `ft_getopt_long_only`.
```c
/*
  standard library uses the following for getopt_long and getopt_long_only
*/

(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);


/*
  and in ft_getopt we use the following
*/
(t_getopt_arg arg, const char *optstring, const t_option *longopts, int *longindex);
```

The reason for this is rather obvious, in **42** we can not use more then 4 function parameters and to make it compatible with **42** `norm` we used a structure called `t_getopt_arg` were where we can indicate the **argc** and **argv**.

The structure is defined as following:
```c
typedef struct	s_getopt_arg
{
	int	argc;
	char	**argv;
}		t_getopt_arg;
```

other than those two differences there aren't any other differences.

# t_option

As **42** norm implies that for any `struct` we use the suffix **s_** and for any `typedef` we use **t_** thus the implementation of the structure `option` became `t_option`.

The structure is declared as following:
```c
typedef struct	s_option
{
	const char	*name;	/* The long option name */
	int		has_arg;
	int		*flag; 	/*
					If null then returns value,
					else saven the value of val
				*/

	int		val;	/*
					If f*lag is null then returns the value of
					val else saves the value of val in *flag
				*/
}		t_option;
```


# Behavior
All the function from this library behave the same as standard library functions, the return the same values, they print the same error message the same way. Other then the differences mention above they are used as the functions provided by the standard library functions.

# External functions and library used for ft_getopt
|Library| function|
|--------|--------|
|libft| `ft_memalloc`|
|libft| `ft_memdel`|
|libft| `ft_strdup`|
|libft| `ft_strlen`|
|ft_printf_err| `ft_printf_err`|
