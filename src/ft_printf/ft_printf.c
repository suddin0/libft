/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samad <samad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 05:09:29 by samad             #+#    #+#             */
/*   Updated: 2018/01/27 23:19:15 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline	void	data_init(t_pdata *print, t_ppnt *flag_pnt)
{
	print->len = 0;
	print->data_len = 0;
	print->flags = 0;
	print->tstart = 0;
	print->tend = 0;
	flag_pnt->i = 0;
	flag_pnt->count = 0;
	flag_pnt->flag1 = 0;
	flag_pnt->start = 0;
}

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

static inline void		ft_printf_extra(va_list args, t_ppnt *flag_pnt, \
		char *str, t_pdata *print)
{
	va_list args_cpy;

	while (str[flag_pnt->i])
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

int						ft_printf(const char *restrict format, ...)
{
	t_pdata	print[1];
	t_ppnt	flag_pnt;
	char	*str;
	int		len;
	va_list args;

	if (!format)
		return (-1);
	str = (char *)format;
	va_start(args, format);
	data_init(print, &flag_pnt);
	func_init(&flag_pnt);
	if (str[1] == 0 && str[0] == '%')
		return (0);
	ft_printf_extra(args, &flag_pnt, str, print);
	print->tend = flag_pnt.i;
	data_man(print, (t_uchar *)str, print->tstart, print->tend);
	write(1, print->data, print->data_len);
	len = print->len;
	va_end(args);
	return (len);
}
