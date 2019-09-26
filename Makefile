###############################################################################
##                                                                           ##
##  This is a generalized makefiles made to be used on different kind        ##
##  of projects, such as making libraries , source files etc.                ##
##  Please note that to use this make files you need to posses the `.misc`   ##
##  directory that is included in the repo by default. This path is needed   ##
##  as some files used by make files are included there. Do change anything  ##
##  dependeing on your need.                                                 ##
##                                                                           ##
##  In the file `color` located in `.misc/make` you can find terminal escape ##
##  codes for colors arr or remove or eddid to get result as you want.       ##
##                                                                           ##
##                                                                           ##
##  In the file `path` located in `.misc/make` information about varius paths##
##  are included for to make this Makefile easier and to manage the make file##
##  More easily.                                                             ##
##                                                                           ##
###############################################################################


## Please do not remove the includes
## as they contain impoirtent information
## variables and rules

include .misc/make/color
include .misc/make/paths
include .misc/make/misc_var

## Te `.SILENT` launche evrything specified in
## silent mode so you dont have to put the `@`
.SILENT	: __START	NAME	clean fclean all re object library printf_object library printf_err_object printf_library printf_err_library os_dep ft_printf ft_printf_err
.PHONY	: __START			clean fclean all re object library printf_object library printf_err_object printf_library printf_err_library os_dep ft_printf ft_printf_err


## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	LIBFT

## compiler related
CC		?=	clang 		## default compiler is clang


CFLAGS					?=	-Werror -Wall -Wextra

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
## -fno-omit-frame-pointer		\
## -fsanitize-address-use-after-scope \

INCLUDE = include

## binary, library etc...
MAIN	?=	main.c
NAME	?=	libft 		## The name of your binary

#The name of the library you want to make
LIB_A			?=	$(P_LIB)/libft.a

P_PRINTF_SRC	= src/printf_src
P_LIBFT_SRC		= src/libft_src
P_GETOPT_SRC	= src/getopt_src


## sources and objects where path names are removed.
## Add all your source files to this variable
LIBFT_SRC =		$(P_LIBFT_SRC)/ft_bzero.c							\
				$(P_LIBFT_SRC)/ft_memset.c							\
				$(P_LIBFT_SRC)/ft_memcpy.c							\
				$(P_LIBFT_SRC)/ft_memccpy.c							\
				$(P_LIBFT_SRC)/ft_memmove.c							\
				$(P_LIBFT_SRC)/ft_memchr.c							\
				$(P_LIBFT_SRC)/ft_memcmp.c							\
				$(P_LIBFT_SRC)/ft_strlen.c							\
				$(P_LIBFT_SRC)/ft_strdup.c							\
				$(P_LIBFT_SRC)/ft_strdupl.c							\
				$(P_LIBFT_SRC)/ft_strcpy.c							\
				$(P_LIBFT_SRC)/ft_strncpy.c							\
				$(P_LIBFT_SRC)/ft_strcat.c							\
				$(P_LIBFT_SRC)/ft_strncat.c							\
				$(P_LIBFT_SRC)/ft_strlcat.c							\
				$(P_LIBFT_SRC)/ft_strchr.c							\
				$(P_LIBFT_SRC)/ft_strrchr.c							\
				$(P_LIBFT_SRC)/ft_strstr.c							\
				$(P_LIBFT_SRC)/ft_strnstr.c							\
				$(P_LIBFT_SRC)/ft_strcmp.c							\
				$(P_LIBFT_SRC)/ft_strncmp.c							\
				$(P_LIBFT_SRC)/ft_atoi.c							\
				$(P_LIBFT_SRC)/ft_isalpha.c							\
				$(P_LIBFT_SRC)/ft_isdigit.c							\
				$(P_LIBFT_SRC)/ft_isalnum.c							\
				$(P_LIBFT_SRC)/ft_isascii.c							\
				$(P_LIBFT_SRC)/ft_isprint.c							\
				$(P_LIBFT_SRC)/ft_toupper.c							\
				$(P_LIBFT_SRC)/ft_tolower.c							\
				$(P_LIBFT_SRC)/ft_memalloc.c						\
				$(P_LIBFT_SRC)/ft_memdel.c							\
				$(P_LIBFT_SRC)/ft_strnew.c							\
				$(P_LIBFT_SRC)/ft_strdel.c							\
				$(P_LIBFT_SRC)/ft_strclr.c							\
				$(P_LIBFT_SRC)/ft_striter.c							\
				$(P_LIBFT_SRC)/ft_striteri.c						\
				$(P_LIBFT_SRC)/ft_strmap.c							\
				$(P_LIBFT_SRC)/ft_strmapi.c							\
				$(P_LIBFT_SRC)/ft_strequ.c							\
				$(P_LIBFT_SRC)/ft_strnequ.c							\
				$(P_LIBFT_SRC)/ft_strsub.c							\
				$(P_LIBFT_SRC)/ft_strjoin.c							\
				$(P_LIBFT_SRC)/ft_strtrim.c							\
				$(P_LIBFT_SRC)/ft_strsplit.c						\
				$(P_LIBFT_SRC)/ft_itoa.c							\
				$(P_LIBFT_SRC)/ft_putchar.c							\
				$(P_LIBFT_SRC)/ft_putnchar.c						\
				$(P_LIBFT_SRC)/ft_putstr.c							\
				$(P_LIBFT_SRC)/ft_putendl.c							\
				$(P_LIBFT_SRC)/ft_putnbr.c							\
				$(P_LIBFT_SRC)/ft_putchar_fd.c						\
				$(P_LIBFT_SRC)/ft_putstr_fd.c						\
				$(P_LIBFT_SRC)/ft_putendl_fd.c						\
				$(P_LIBFT_SRC)/ft_putnbr_fd.c						\
				$(P_LIBFT_SRC)/ft_lstnew.c							\
				$(P_LIBFT_SRC)/ft_lstdelone.c						\
				$(P_LIBFT_SRC)/ft_lstdel.c							\
				$(P_LIBFT_SRC)/ft_lstadd.c							\
				$(P_LIBFT_SRC)/ft_lstiter.c							\
				$(P_LIBFT_SRC)/ft_lstmap.c							\
				$(P_LIBFT_SRC)/ft_strrev.c							\
				$(P_LIBFT_SRC)/ft_intlen.c							\
				$(P_LIBFT_SRC)/ft_abs.c								\
				$(P_LIBFT_SRC)/ft_strresize.c						\
				$(P_LIBFT_SRC)/ft_strrem.c							\
				$(P_LIBFT_SRC)/ft_sqrt.c							\
				$(P_LIBFT_SRC)/ft_putnbrendl.c						\
				$(P_LIBFT_SRC)/ft_chrindex.c						\
				$(P_LIBFT_SRC)/ft_chrindexi.c						\
				$(P_LIBFT_SRC)/ft_strjoini.c						\
				$(P_LIBFT_SRC)/ft_strchri.c

PRINTF_SRC =	$(P_PRINTF_SRC)/print/ft_printf.c					\
		  		$(P_PRINTF_SRC)/print/ft_dprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_sprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_snprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_vprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_vdprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_vsprintf.c					\
		  		$(P_PRINTF_SRC)/print/ft_vsnprintf.c				\
		  		$(P_PRINTF_SRC)/printf_internal.c					\
		  		$(P_PRINTF_SRC)/str_to_pointer.c					\
		  		$(P_PRINTF_SRC)/format_verif.c						\
		  		$(P_PRINTF_SRC)/format_verif_extra.c				\
		  		$(P_PRINTF_SRC)/is_flag.c							\
		  		$(P_PRINTF_SRC)/flag_man.c							\
		  		$(P_PRINTF_SRC)/write_data/data_man.c				\
		  		$(P_PRINTF_SRC)/write_data/dataset.c				\
		  		$(P_PRINTF_SRC)/simple_sort.c						\
		  		$(P_PRINTF_SRC)/get_next_arg_int.c					\
		  		$(P_PRINTF_SRC)/hier_man.c							\
		  		$(P_PRINTF_SRC)/get_arg/arg_llint.c					\
		  		$(P_PRINTF_SRC)/get_arg/arg_ullint.c				\
		  		$(P_PRINTF_SRC)/get_arg/arg_uint.c					\
		  		$(P_PRINTF_SRC)/get_arg/arg_str.c					\
		  		$(P_PRINTF_SRC)/get_arg/arg_void.c					\
		  		$(P_PRINTF_SRC)/get_arg/arg_wcharc.c				\
		  		$(P_PRINTF_SRC)/get_arg/arg_wchars.c				\
		  		$(P_PRINTF_SRC)/field_proc.c						\
		  		$(P_PRINTF_SRC)/multi_verif/multi_verif.c			\
		  		$(P_PRINTF_SRC)/multi_verif/verif_f1.c				\
		  		$(P_PRINTF_SRC)/multi_verif/verif_f2.c				\
		  		$(P_PRINTF_SRC)/multi_verif/verif_f3.c				\
		  		$(P_PRINTF_SRC)/multi_verif/verif_l1.c				\
		  		$(P_PRINTF_SRC)/multi_verif/verif_l2.c				\
		  		$(P_PRINTF_SRC)/multi_verif/verif_l3.c				\
		  		$(P_PRINTF_SRC)/flags/string/printf_string.c		\
		  		$(P_PRINTF_SRC)/flags/char/printf_char.c			\
		  		$(P_PRINTF_SRC)/flags/percent/printf_percent.c		\
		  		$(P_PRINTF_SRC)/flags/number/printf_number.c		\
		  		$(P_PRINTF_SRC)/flags/decimal/printf_int_extra.c	\
		  		$(P_PRINTF_SRC)/flags/decimal/printf_int.c			\
		  		$(P_PRINTF_SRC)/flags/decimal/printf_uint.c			\
		  		$(P_PRINTF_SRC)/flags/decimal/printf_uuint.c		\
		  		$(P_PRINTF_SRC)/flags/decimal/printf_lint.c			\
		  		$(P_PRINTF_SRC)/flags/base/printf_base_extra.c		\
		  		$(P_PRINTF_SRC)/flags/base/printf_base.c			\
		  		$(P_PRINTF_SRC)/flags/base/printf_ubase.c			\
		  		$(P_PRINTF_SRC)/flags/pointer/printf_pointer.c		\
		  		$(P_PRINTF_SRC)/flags/wchar/printf_wcharc.c			\
		  		$(P_PRINTF_SRC)/flags/wchar/printf_wchars.c			\
		  		$(P_PRINTF_SRC)/flags/wchar/w_to_char.c				\


GETOPT_SRC =	$(P_GETOPT_SRC)/ft_getopt_long.c						\
				$(P_GETOPT_SRC)/ft_getopt_long_only.c					\
				$(P_GETOPT_SRC)/ft_getopt.c								\
				$(P_GETOPT_SRC)/getopt_data.c							\
				$(P_GETOPT_SRC)/optvar/get_optvar.c						\
				$(P_GETOPT_SRC)/optvar/get.c							\
				$(P_GETOPT_SRC)/optvar/set.c							\
				$(P_GETOPT_SRC)/getopt_internal/getopt_internal.c		\
				$(P_GETOPT_SRC)/getopt_internal/internal_args_init.c	\
				$(P_GETOPT_SRC)/getopt_internal/getopt_internal_short.c	\
				$(P_GETOPT_SRC)/getopt_internal/getopt_internal_long.c	\
				$(P_GETOPT_SRC)/set_next_opt.c							\
				$(P_GETOPT_SRC)/argv_mutate.c							\
				$(P_GETOPT_SRC)/option_type.c							\
				$(P_GETOPT_SRC)/getopt_end.c							\

SRC =			$(LIBFT_SRC)	\
				$(PRINTF_SRC)	\
				$(GETOPT_SRC)	\

HEADERS =		$(INCLUDE)/ft_printf.h			\
				$(INCLUDE)/ft_printf_extra.h	\
				$(INCLUDE)/libft.h				\
				$(INCLUDE)/ft_getopt.h			\

## Objects without path names
OBJ		:=	$(addsuffix .o, $(basename $(SRC)))
PRINTF_OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the
											## path name to the files...
## Start making here
__START: os all

all: $(NAME)

$(NAME):  $(P_LIB) $(LIB_A)

$(LIB_A): $(OBJ) $(P_LIB)
	@ar rc $(LIB_A) $(OBJ)
	@printf "ar rc $(LIB_A) *.o\n"
	@ranlib $(LIB_A)
	@printf "ranlib $(LIB_A)\n"

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o  $@ $<

re:	 fclean
	@make --no-print-directory

## Clean objects and others
clean:
	rm		-f	$(OBJ)
	printf "$(WARN)[!][$(PROJECT)] Removed all objects from$(C_DEF)\n"
	printf "$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	rm		-f	$(LIB_A) $(PRINTF_LIB_A)
	printf "$(WARN)[!][$(PROJECT)] Removed $(LIB_A)$(C_DEF)\n"
	rm -rf $(P_LIB)
	printf "$(WARN)[!][$(PROJECT)] Removed $(P_LIB) directory$(C_DEF)\n"
	printf "$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"


## This rule is called when a difference in operating sistem has been
## detected. You can put your prerequisite to be changed if a different
## os has been detected
os_dep: #put your prerequisite for os dependent stufs
	## put your os dependent comands here
	## this will be launched if the os name is
	## different then what read from the os file.
	## ex: make re
	printf "$(WARN)[!][$(PROJECT)] Os dependent stufs $(C_DEF)\n"

## Useful Makefile tricks
##
## ?= 			// let you put a default variable then later change it
## j<number>	// let you launche the number of job at the same time
## ifdef		// let you verify if used defined something or not
## .SILENT		// This parameter let you launch rules in silent mod
## .IGNORE		// Ignore parameter used as .SILENT
#
## --stop-on-faliur			// stop the program if error occures
## -k or --keep-going		// To keep ignoring all errors
## -i or --ignore-errors	// To Ignor error
## --no-print-directory		// This do not show the 'entered ... directory' warning
