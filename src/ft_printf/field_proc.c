/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 09:02:42 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 09:59:02 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
	int		val_tmp[8];
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
