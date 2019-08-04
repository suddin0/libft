#include "ft_getopt.h"



static void getopt_data_init(t_getopt_data *getopt_data)
{
	if(!getopt_data)
		return ;

	getopt_data->initialized = GETOPT_INITIALIZED;
	getopt_data->optarg = NULL;
	getopt_data->optind = 1;
	getopt_data->opterr = 1;
	getopt_data->optopt = 0;
	getopt_data->nextchar = 0;
	getopt_data->last_optind = 0;
}

t_getopt_data *get_getopt_data()
{
	static t_getopt_data getopt_data = {0};

	if(!getopt_data.initialized)
		getopt_data_init(&getopt_data);
	return(&getopt_data);
}
