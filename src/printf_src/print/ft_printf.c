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
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	return (printf_internal(FT_STDOUT_FD, format, args));
	va_end(args);
}
