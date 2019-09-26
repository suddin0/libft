/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samad <samad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 05:09:29 by samad             #+#    #+#             */
/*   Updated: 2019/08/07 00:10:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	This function initialise the internal data structure on which the core
	printf_internal depend to print and for other stuff.
*/
static inline	void	data_init(t_pdata *print, t_ppnt *flag_pnt, t_piopt opt)
{
	print->data = opt.buff;
	print->data_size = opt.buff_size;
	print->len = 0;
	print->data_len = 0;
	print->flags = 0;
	print->tstart = 0;
	print->tend = 0;
	print->fd = opt.fd;
	print->ret_on_full = opt.ret_on_full;
	flag_pnt->i = 0;
	flag_pnt->count = 0;
	flag_pnt->flag1 = 0;
	flag_pnt->start = 0;
}

/*
	This function initiate the function table which is called during data
	formating.
*/
static inline	void	func_init(t_ppnt *flag_pnt)
{
	(flag_pnt->func)[0] = printf_string;
	(flag_pnt->func)[1] = printf_char;
	(flag_pnt->func)[2] = printf_int;
	(flag_pnt->func)[3] = printf_pointer;
	(flag_pnt->func)[4] = printf_percent;
	(flag_pnt->func)[5] = printf_number;
	(flag_pnt->func)[6] = printf_uint;
	(flag_pnt->func)[7] = printf_base;
	(flag_pnt->func)[8] = printf_ubase;
	(flag_pnt->func)[9] = printf_base;
	(flag_pnt->func)[10] = printf_base;
	(flag_pnt->func)[11] = printf_int;
	(flag_pnt->func)[12] = printf_uuint;
	(flag_pnt->func)[13] = printf_lint;
	(flag_pnt->func)[14] = printf_wcharc;
	(flag_pnt->func)[15] = printf_wchars;
}

int break_condition(t_pdata *print)
{
	if(print->ret_on_full && print->len >= print->data_size)
		return (0);
	else
		return (1);
}

/*
	The following function is an extention if `printf_internal` as the 42 norm
	require that the functions be at max 25 lines.

	This function loop over the string containing the formats and treat as
	requiored.
*/
static inline void		ft_printf_extra(va_list args, t_ppnt *flag_pnt, \
		char *str, t_pdata *print)
{
	va_list args_cpy;

	while (str[flag_pnt->i] && break_condition(print))
	{
		if (flag_pnt->flag1 > 0)
		{
			flag_pnt->count += (flag_pnt->flag1 = is_flag(str[flag_pnt->i]));
			if ((flag_pnt->count > 0 && (flag_pnt->flag1 == 1
				|| flag_pnt->flag1 == 0)) || str[flag_pnt->i + 1] == '\0')
			{
				va_copy(args_cpy, args);
				flag_man(print, flag_pnt, str, args_cpy);
				va_end(args_cpy);
				(flag_pnt->i)++;
				continue;
			}
		}
		if (str[flag_pnt->i] == '%')
		{
			flag_pnt->flag1 = 1;
			flag_pnt->start = flag_pnt->i;
		}
		(flag_pnt->i)++;
	}
}


/*
	The following function parse the text and format it. This is the core of all
	printf functions.
*/

int						printf_internal(t_piopt opt,\
	const char *restrict format, va_list args)
{
	t_pdata	print[1];
	t_ppnt	flag_pnt;
	char	*str;
	int		len;

	if (!format)
		return (-1);
	str = (char *)format;
	data_init(print, &flag_pnt, opt);
	func_init(&flag_pnt);
	if (str[0] == '%' && str[1] == 0)
		return (0);
	ft_printf_extra(args, &flag_pnt, str, print);
	print->tend = flag_pnt.i;
	data_man(print, (t_uchar *)str, print->tstart, print->tend);
	if(print->fd > -1)
		write(print->fd, print->data, print->data_len);
	len = print->len;
	return (len);
}
