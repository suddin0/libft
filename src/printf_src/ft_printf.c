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

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	return(printf_internal(FT_STDOUT_FD, format, args));
}
