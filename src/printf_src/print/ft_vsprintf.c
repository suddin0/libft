/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:52:24 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:21:47 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_piopt opt;

	if (!format)
		return (-1);
	opt.buff = (t_uchar *)str;
	opt.buff_size = -1;
	opt.fd = -1;
	opt.ret_on_full = 0;
	return (printf_internal(opt, format, ap));
}
