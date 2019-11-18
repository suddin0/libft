/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:08:02 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:19:55 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

void	printf_number(t_pdata *print, t_pflag *flags, va_list args)
{
	void	*num;

	num = NULL;
	num = field_proc(print, flags, args, (void *)arg_void);
	if (flags->length == 0)
		*((int *)num) = (int)print->len;
	else if (flags->length == 7)
		*((char *)num) = (char)print->len;
	else if (flags->length == 1)
		*((short int *)num) = (short int)print->len;
	else if (flags->length == 6)
		*((long long *)num) = (long long)print->len;
	else if (flags->length == 2)
		*((long *)num) = (long)print->len;
	else if (flags->length == 3)
		*((intmax_t *)num) = (intmax_t)print->len;
	else if (flags->length == 4)
		*((size_t *)num) = (size_t)print->len;
	else if (flags->length == 5)
		*((ptrdiff_t *)num) = (ptrdiff_t)print->len;
}
