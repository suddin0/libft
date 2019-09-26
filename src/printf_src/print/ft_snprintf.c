/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:51:17 by suddin            #+#    #+#             */
/*   Updated: 2019/09/26 20:51:26 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list	args;
	t_piopt	opt;
	int		len;

	if (!format)
		return (-1);
	opt.buff = (t_uchar *)str;
	opt.buff_size = size;
	opt.fd = -1;
	opt.ret_on_full = 1;
	va_start(args, format);
	len = printf_internal(opt, format, args);
	va_end(args);
	return (len);
}
