#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_getopt.h"

#define RED		"\e[38;5;196m"
#define WHITE	"\e[38;5;15m"

#define CONTINUE	1
#define STOP		0


char **argvdup(int argc, char **argv);
void argv_free(int argc, char **argv);

int compare_argv(int argc, char **a, char **b);
int optarg_cmp(char *a, char *b);

int check_diff(
	int ret_getopt,
	int ret_ft_getopt,
	int argc,
	char **argv,
	char **argv_getopt,
	char **argv_ft_getopt,
	struct option	longopt[],
	int glongind,
	int flongind
);


#endif
