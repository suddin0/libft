#include "libft.h"

/**
* The following file is used to save the name of the program
* So that you can use this name elsewhere.
*
* Usage:
*
* Call the `set_program_name` in the begining of your program
* se we save the name in a static variable. Normally you would
* like to pass the argv[0] (the farst command line argument) to
* the `set_program_name` function.
*
* later you will call the function `get_program_name` to retreat
* the name from anywhere.
**/

static char *program_name_ptr()
{
    static char name[MAX_PROGRAM_NAME];
    return (name);
}

int set_program_name(char *n_name)
{
    char    *name;
    int     n_name_size;

    name = program_name_ptr();
    if(!n_name || name[0])
        return (-1);
    n_name_size = ft_strlen(n_name);

    if(n_name_size >= MAX_PROGRAM_NAME)
        ft_strcpy(name, &(n_name[n_name_size - MAX_PROGRAM_NAME]));
    else
        ft_strcpy(name, n_name);
    return (0);
}

const char *get_program_name()
{
    return (program_name_ptr());
}