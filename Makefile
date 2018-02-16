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
.SILENT	: __START	NAME	clean fclean all re object library printf_object printf_library os_dep ft_printf
.PHONY	: __START			clean fclean all re object library printf_object printf_library os_dep ft_printf


## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	LIBFT

## compiler related
CC		?=	clang 		## default compiler is clang


CC_FLAG					?=	-Werror -Wall -Wextra
PRINTF_CC_FLAG			?=	-Werror -Wall -Wextra -Ofast
PRINTF_LIBFT_CC_FLAG	?=	-Werror -Wall -Wextra -O3

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
## -fno-omit-frame-pointer		\
## -fsanitize-address-use-after-scope \

INCLUDE = include

## binary, library etc...
MAIN	?=	main.c
NAME	?=	$(P_LIB)/libft.a 		## The name of your binary

#The name of the library you want to make
LIB_A			?=	$(P_LIB)/libft.a
PRINTF_LIBFT_A	?=	$(P_LIB)/pf_libft.a
PRINTF_LIB_A	?=	$(P_LIB)/libftprintf.a


## sources and objects where path names are removed.
## Add all your source files to this variable
SRC		=	src/ft_bzero.c										\
			src/ft_memset.c										\
			src/ft_memcpy.c										\
			src/ft_memccpy.c									\
			src/ft_memmove.c									\
			src/ft_memchr.c										\
			src/ft_memcmp.c										\
			src/ft_strlen.c										\
			src/ft_strdup.c										\
			src/ft_strdupl.c									\
			src/ft_strcpy.c										\
			src/ft_strncpy.c									\
			src/ft_strcat.c										\
			src/ft_strncat.c									\
			src/ft_strlcat.c									\
			src/ft_strchr.c										\
			src/ft_strrchr.c									\
			src/ft_strstr.c										\
			src/ft_strnstr.c									\
			src/ft_strcmp.c										\
			src/ft_strncmp.c									\
			src/ft_atoi.c										\
			src/ft_isalpha.c									\
			src/ft_isdigit.c									\
			src/ft_isalnum.c									\
			src/ft_isascii.c									\
			src/ft_isprint.c									\
			src/ft_toupper.c									\
			src/ft_tolower.c									\
			src/ft_memalloc.c									\
			src/ft_memdel.c										\
			src/ft_strnew.c										\
			src/ft_strdel.c										\
			src/ft_strclr.c										\
			src/ft_striter.c									\
			src/ft_striteri.c									\
			src/ft_strmap.c										\
			src/ft_strmapi.c									\
			src/ft_strequ.c										\
			src/ft_strnequ.c									\
			src/ft_strsub.c										\
			src/ft_strjoin.c									\
			src/ft_strtrim.c									\
			src/ft_strsplit.c									\
			src/ft_itoa.c										\
			src/ft_putchar.c									\
			src/ft_putnchar.c									\
			src/ft_putstr.c										\
			src/ft_putendl.c									\
			src/ft_putnbr.c										\
			src/ft_putchar_fd.c									\
			src/ft_putstr_fd.c									\
			src/ft_putendl_fd.c									\
			src/ft_putnbr_fd.c									\
			src/ft_lstnew.c										\
			src/ft_lstdelone.c									\
			src/ft_lstdel.c										\
			src/ft_lstadd.c										\
			src/ft_lstiter.c									\
			src/ft_lstmap.c										\
			src/ft_strrev.c										\
			src/ft_intlen.c										\
			src/ft_abs.c										\
			src/ft_strresize.c									\
			src/ft_strrem.c										\
			src/ft_sqrt.c										\
			src/ft_putnbrendl.c									\
			src/ft_chrindex.c									\
			src/ft_chrindexi.c									\
			src/ft_strjoini.c									\
			src/ft_strchri.c

PRINTF_SRC =	src/ft_printf/ft_printf.c						\
		  		src/ft_printf/format_verif.c					\
		  		src/ft_printf/format_verif_extra.c				\
		  		src/ft_printf/is_flag.c							\
		  		src/ft_printf/flag_man.c						\
		  		src/ft_printf/data_man.c						\
		  		src/ft_printf/dataset.c							\
		  		src/ft_printf/simple_sort.c						\
		  		src/ft_printf/get_next_arg_int.c				\
		  		src/ft_printf/hier_man.c						\
		  		src/ft_printf/get_arg/arg_llint.c				\
		  		src/ft_printf/get_arg/arg_ullint.c				\
		  		src/ft_printf/get_arg/arg_uint.c				\
		  		src/ft_printf/get_arg/arg_str.c					\
		  		src/ft_printf/get_arg/arg_void.c				\
		  		src/ft_printf/get_arg/arg_wcharc.c				\
		  		src/ft_printf/get_arg/arg_wchars.c				\
		  		src/ft_printf/field_proc.c						\
		  		src/ft_printf/multi_verif/multi_verif.c			\
		  		src/ft_printf/multi_verif/verif_f1.c			\
		  		src/ft_printf/multi_verif/verif_f2.c			\
		  		src/ft_printf/multi_verif/verif_f3.c			\
		  		src/ft_printf/multi_verif/verif_l1.c			\
		  		src/ft_printf/multi_verif/verif_l2.c			\
		  		src/ft_printf/multi_verif/verif_l3.c			\
		  		src/ft_printf/flags/string/printf_string.c		\
		  		src/ft_printf/flags/char/printf_char.c			\
		  		src/ft_printf/flags/percent/printf_percent.c	\
		  		src/ft_printf/flags/number/printf_number.c		\
		  		src/ft_printf/flags/decimal/printf_int_extra.c	\
		  		src/ft_printf/flags/decimal/printf_int.c		\
		  		src/ft_printf/flags/decimal/printf_uint.c		\
		  		src/ft_printf/flags/decimal/printf_uuint.c		\
		  		src/ft_printf/flags/decimal/printf_lint.c		\
		  		src/ft_printf/flags/base/printf_base_extra.c	\
		  		src/ft_printf/flags/base/printf_base.c			\
		  		src/ft_printf/flags/base/printf_ubase.c			\
		  		src/ft_printf/flags/pointer/printf_pointer.c	\
		  		src/ft_printf/flags/wchar/printf_wcharc.c		\
		  		src/ft_printf/flags/wchar/printf_wchars.c		\
		  		src/ft_printf/flags/wchar/w_to_char.c			\


## Objects without path names
OBJ		:=	$(notdir $(SRC:.c=.o))
PRINTF_OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the 
											## path name to the files...
## Start making here
__START: os all
	 printf "$(OK)[+][$(PROJECT)] Done $(C_DEF)\n"

# ------------ Libft Library --------------
all: $(NAME)

$(NAME): $(SRC)
	@make library --no-print-directory


re:			fclean $(NAME)

## This function creat object files from sources.
## It treates the string of large source names as
## individual names, when it creat objects it do
## not gives al the names in the same time to gcc
## but one by one.
object:	$(SRC) $(P_SRC) $(P_OBJ) 
	$(foreach SOURCE, $(SRC), \
		$(CC) $(CC_FLAG) -I$(INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
		printf "$(OK)[+][$(PROJECT)] $(SOURCE)$(C_DEF)" && sleep $(SLEEP)	&& \
		printf "\r\033[K" \
	;)
	printf "$(OK)[+][$(PROJECT)] Objects are made in ./$(P_OBJ)$(C_DEF)\n"

## Make the actual library (archive)
library:  object $(P_LIB) $(OBJ_P) $(P_OBJ)
	printf "$(WARN)[!][$(PROJECT)] Creating archive $(LIB_A)$(C_DEF)\n"
	@ar rc $(LIB_A) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Generating index in $(LIB_A)$(C_DEF)\n"
	@ranlib $(LIB_A)
	printf "$(OK)[+][$(PROJECT)] The $(LIB_A) library was made$(C_DEF)\n"

# ------------ Libft Library END --------------

# ------------ Printf Library --------------
# In this compilation we remake the libft with other flags for optimisation purposes
#PRINTF_LIIBFT_A ?=	pf_libft.a
 ft_printf:	$(PRINTF_LIB_A)
	printf "$(OK)[+][FT_PRINTF] Done $(C_DEF)\n"

$(PRINTF_LIB_A): $(PRINTF_SRC) $(PRINTF_LIBFT_A)
	@make  CC_FLAG=$(PRINTF_CC_FLAG) printf_library --output-sync=target --no-print-directory

$(PRINTF_LIBFT_A):
	@make clean --no-print-directory
	@make CC_FLAG=$(PRINTF_LIBFT_CC_FLAG) 	LIB_A=$(PRINTF_LIBFT_A) NAME=LIB_A=$(PRINTF_LIBFT_A) --output-sync=target --no-print-directory



printf_object:	$(SRC) $(P_SRC) $(P_OBJ)
	$(foreach SOURCE, $(PRINTF_SRC), \
		$(CC) $(CC_FLAG) -I $(INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
		printf "$(OK)[+]$(C_DEF)[FT_PRINTF]$(OK) $(SOURCE)$(C_DEF)" && sleep $(SLEEP) && \
		printf "\r\033[K" \
		;)
	printf "$(OK)[+]$(C_DEF)[FT_PRINTF]$(OK) Objects are made in ./$(P_OBJ)$(C_DEF)\n"

## Make the actual library (archive)
printf_library:	printf_object $(P_OBJ) $(P_LIB)
	printf "$(WARN)[!]$(C_DEF)[FT_PRINTF]$(WARN) Creating archive $(PRINTF_LIB_A)$(C_DEF)\n"
	@ar rc $(PRINTF_LIB_A)  $(OBJ_W)
	printf "$(WARN)[!]$(C_DEF)[FT_PRINTF]$(WARN) Generating index in $(PRINTF_LIB_A)$(C_DEF)\n"
	@ranlib $(PRINTF_LIB_A)
	printf "$(OK)[+]$(C_DEF)[FT_PRINTF]$(OK) The $(PRINTF_LIB_A) library was made$(C_DEF)\n"
# ------------ Printf Library END --------------




## Clean objects and others
clean: $(P_OBJ) $(P_LIB)
	rm		-f	$(OBJ_W)
	printf "$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf "$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	rm		-f	$(LIB_A) $(PRINTF_LIB_A)
	printf "$(WARN)[!][$(PROJECT)] Removed $(LIB_A) and $(PRINTF_LIB_A)$(C_DEF)\n"
	rm -rf $(P_OBJ) $(P_LIB)
	printf "$(WARN)[!][$(PROJECT)] Removed $(P_OBJ) and $(P_LIB) directory$(C_DEF)\n"
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
