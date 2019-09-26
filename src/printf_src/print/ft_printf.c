/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 00:09:44 by suddin            #+#    #+#             */
/*   Updated: 2019/08/07 00:09:59 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	t_piopt	opt;
	t_uchar	buff[P_BUFF_SIZE + 1];
	int		len;

	if (!format)
		return (-1);
	opt.buff = str_to_pointer(buff);
	opt.buff_size = P_BUFF_SIZE;
	opt.fd = FT_STDOUT_FD;
	opt.ret_on_full = 0;
	va_start(args, format);
	len = printf_internal(opt, format, args);
	va_end(args);
	return (len);
}
