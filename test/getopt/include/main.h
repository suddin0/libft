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

#endif
