#include "ft_getopt.h"

int option_type(char *opt)
{
	/*
		type represents the type of option (shirt or long).
		if type :
			0 : not a valide option
			1 : short option
			2 : long option
	*/
	int type;

	type = OPT_TYPE_NONE;
	if(!opt)
		return (OPT_TYPE_NONE);

	if(opt[type] == '-')
		type++;
	if(opt[type] == '-')
		type++;

	/* If there is only one character then it's not a valid option */
	if(type == 1 && opt[type] == 0)
		return(OPT_TYPE_NONE);
	/* If the option is the special case `--` the nsend a particular notification */
	else if(type == 2 && opt[type] == 0)
		return(OPT_TYPE_END);

	if(type == 1)
		return(OPT_TYPE_SHORT);
	else if(type == 2)
		return(OPT_TYPE_LONG);
	else
		return (type);
}
