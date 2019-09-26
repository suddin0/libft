/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hier_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:56:59 by suddin            #+#    #+#             */
/*   Updated: 2018/04/27 08:01:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* *****************************************************************************
	This function helps us determinat in what order we should call the specific
	function depending on the flags, read allready and the custom argument
	values.

	As we do not know how the user have wrote the flag so we need to find a way
	to automate the system so that no metter in what order the user chose the
	argument specified we shell allways get the right one wothout using multiple
	copies of va_list, in other word we should think of a way so that we can
	decide the right hierarchy of the flag depening on the values specified,
	for	exemple: printf("%4$*.*1s", 22, "a", "b", "c");

	In the above example the user chosed the fourth argument as (to print) as
	string, the next argument to read as the width (*) and the first argument
	as it's precision which is also the width in our case. So in this case we
	have to make sure we get the right argument for the right use and. To know
	more about the custom argument chosing, see the section [custom] of .info
	file.

	This is a generic function as it is not dependent on any specific case and
	can be used in other cases.
***************************************************************************** */

static void	var_init(int *array, int *val_tmp, char flag)
{
	if (flag == 0)
	{
		val_tmp[0] = 0;
		val_tmp[1] = 0;
		val_tmp[2] = 0;
		val_tmp[3] = 0;
	}
	else
	{
		array[0] = val_tmp[0];
		array[1] = val_tmp[1];
		array[2] = val_tmp[2];
	}
}

/*
	The following function is a `` Hierarchy Manager
*/
void		hier_man(t_pdata *print, t_pflag *flag, int *array, int *val_tmp)
{
	var_init(array, val_tmp, 0);
	if (flag->width > 1 && flag->width_wild < 0)
		val_tmp[0] = print->flags + 1;
	else
		val_tmp[0] = flag->width_wild;
	if (flag->precis > 1 && flag->precis_wild < 0 && val_tmp[0] != -1)
		val_tmp[1] = print->flags + 2;
	else if (flag->precis > 1 && flag->precis_wild < 0)
		val_tmp[1] = print->flags + 1;
	else
		val_tmp[1] = flag->precis_wild;
	if (flag->flag_arg == -1 && (flag->width == 2 && flag->width_wild == -1) &&\
			flag->precis == 2 && flag->precis_wild == -1)
		val_tmp[2] = print->flags + 3;
	else if (flag->flag_arg == -1 && ((flag->width == 2 && flag->width_wild \
					== -1) || (flag->precis == 2 && flag->precis_wild == -1)))
		val_tmp[2] = print->flags + 2;
	else if (flag->flag_arg > -1)
		val_tmp[2] = flag->flag_arg_val;
	else
		val_tmp[2] = print->flags + 1;
	var_init(array, val_tmp, 1);
}
