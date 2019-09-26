/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:02:42 by suddin            #+#    #+#             */
/*   Updated: 2018/04/27 08:03:27 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* *****************************************************************************
	The function :
	static char *str_fld_cus(t_pdata *print, t_pflag *fl, va_list ag, int i)

	is a part of:
	char *str_field_proc(t_pdata *print, t_pflag *flag, va_list args)

	Separated because of lake of place as more then 25 lignes and 5 variables
	are not allowed to use.

	This function is used to retreat the string data and the data of width and
	precision. It automat string retreaval by calling other functions so that
	in the end programmer get the string from arguments and fill it with
	necessery informations about width and prrecision, it also count the flag
	depending on what type of argument the user want to read (custom or naturel)
	This is not a generic function as it is only used to retreat string type
	argument.
***************************************************************************** */

static void	init(int *i, int *read, int *array)
{
	*i = -1;
	*read = 0;
	simple_sort(array, 3);
}

static void	*fld_cus(t_pdata *print, t_pflag *fl, va_list ag,\
		void *func(int *read, int arg_num, t_pdata *print, va_list args))
{
	void	*rt;
	int		array[4];
	int		val_tmp[12];
	int		read;
	int		i;

	rt = NULL;
	init(&i, &read, array);
	multi_verif(fl, val_tmp, NULL, print->flags);
	hier_man(print, fl, array, val_tmp);
	while (++i != 3)
	{
		if ((array[i] == val_tmp[2]) && val_tmp[3] != 1 && func != NULL)
		{
			if (func != NULL)
				rt = func(&(read), fl->flag_arg_val, print, ag);
			val_tmp[3] = 1;
		}
		else if ((array[i] == val_tmp[0]) && (fl->width > 1))
			fl->width_val = get_next_int(&(read), fl->width_wild, print, ag);
		else if ((array[i] == val_tmp[1]) && (fl->precis > 1))
			fl->precis_val = get_next_int(&(read), fl->precis_wild, print, ag);
	}
	multi_verif(fl, val_tmp, rt, print->flags);
	return (rt);
}

/*
	Field process is a `generic` function whose only goal is to retreav `ANY`
	type of data from the `Variadic` Argument list.

	User MUST pass a function pointer that can retreav a particular type of data
*/
void		*field_proc(t_pdata *print, t_pflag *flag, va_list args,\
		void *func(int *read, int arg_num, t_pdata *print, va_list args))
{
	void	*rt;
	int		read;

	read = 0;
	rt = NULL;
	if (flag->width <= 1 && flag->precis <= 1 && flag->flag_arg == -1)
	{
		if (func != NULL)
			rt = func(&read, flag->flag_arg_val, print, args);
		return (rt);
	}
	if (func != NULL)
		rt = fld_cus(print, flag, args, func);
	return (rt);
}
