/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 00:08:57 by suddin            #+#    #+#             */
/*   Updated: 2019/08/07 00:09:22 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_piopt opt;
	t_uchar buff[P_BUFF_SIZE + 1];

	if (!format)
		return (-1);
	opt.buff = str_to_pointer(buff);
	opt.buff_size = P_BUFF_SIZE;
	opt.fd = fd;
	opt.ret_on_full = 0;
	return (printf_internal(opt, format, ap));
}
