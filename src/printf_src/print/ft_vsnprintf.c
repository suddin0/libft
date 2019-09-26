/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:52:15 by suddin            #+#    #+#             */
/*   Updated: 2019/09/26 20:52:18 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	t_piopt opt;

	if (!format)
		return (-1);
	opt.buff = (t_uchar *)str;
	opt.buff_size = size;
	opt.fd = -1;
	opt.ret_on_full = 1;
	return (printf_internal(opt, format, ap));
}
