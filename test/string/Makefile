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
.SILENT	: __START	NAME	clean fclean all re object library os_dep
.PHONY	: __START			clean fclean all re object library os_dep


## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	PROJECT

## compiler related
CC		?=	clang 		## default compiler is clang

CFLAGS	?=	-Werror \
			-Wall	\
			-Wextra

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
## -fno-omit-frame-pointer		\
## -fsanitize-address-use-after-scope \


## binary, library etc...
MAIN	?=	$(P_SRC)/main.c
NAME	?=	$(PROJECT) 		## The name of your binary

#The name of the library you want to make
LIB_A	?=	$(PROJECT).a

#All LIB_FT stufs
LIBFT		= ../../
LIBFT_INC	= $(LIBFT)/include
LIBFT_LIB	= $(LIBFT)/lib
LIBFT_A		= $(LIBFT_LIB)/libft.a
FT_PRINTF_A	= $(LIBFT_LIB)/libftprintf.a
FT_PRINTF_ERR_A	= $(LIBFT_LIB)/libftprintferr.a
LIBFT_FLAGS = -I $(LIBFT_INC) -L $(LIBFT_LIB) -lft # You can also add -lftprintf -lftprintferr

## sources and objects where path names are removed.
## Add all your source files to this variable
SRC		=		$(MAIN)					\
				#Add other source files here...	\
				#$(P_SRC)/<yourfile>.c	\


## Objects without path names
OBJ		:=	$(addsuffix .o, $(basename $(SRC)))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the
											## path name to the files...

## All header (.h) files so if they changed then all files will be recompiled
HEADERS =	$(P_INCLUDE)/main.h

## Start making here
__START: os_dep
	 @make all --no-print-directory

## For multiple Binarys
all : $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

## Compiles any object file that is added as dependency
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(P_INCLUDE) -c -o  $@ $<

#Default library related
$(LIBFT_A):
	make -C ../../ SHARED=1



## Clean objects and others
clean:
	rm		-f	$(OBJ)
	printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	rm		-f	$(NAME)
	printf	"$(WARN)[!][$(PROJECT)] Removed all binary ./$(P_BIN)$(C_DEF)\n"
	printf	"$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

re:			fclean all



## This rule is called when a difference in operating sistem has been
## detected. You can put your prerequisite to be changed if a different
## os has been detected
os_dep: #put your prerequisite for os dependent stufs
	## put your os dependent comands here
	## this will be launched if the os name is
	## different then what read from the os file.
	## ex: make re
	@printf "[$(PROJECT)] Os dependent stufs\n"

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
