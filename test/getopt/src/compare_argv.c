#include "main.h"


int compare_argv(int argc, char **a, char **b)
{
	int i = 0;
	int error = CONTINUE;

	if(!a || !b)
	{
		printf("\e[38;5;197m[-] Error: arguments %c is NULL\n", !a ? 'a' : 'b');
		return(-1);
	}

	while(i < argc)
	{
		if(optarg_cmp(a[i], b[i]) != 0)
		{
			if(error == CONTINUE)
			{
				ft_printf("Error with argument organization:\n");
				ft_printf("%15.15s | %15.15s\n", "Getopt", "Ft_getopt");
			}
			ft_printf("%15.15s | %s%15.15s%s\n", a[i], RED, b[i], WHITE);
			error = STOP;
		}
		i++;
	}

	return (error);
}
