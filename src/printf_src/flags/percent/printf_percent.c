/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 06:50:29 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:19:59 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

static void	purchent_data_process(t_pdata *print, t_pflag *flags, int str)
{
	int	total;
	int	to_copy;
	int	a;

	a = flags->precis_val;
	to_copy = 1;
	total = (flags->width_val > to_copy) ? flags->width_val : to_copy;
	a = flags->left_just;
	if (a > 0)
		dataset(print, str, 1);
	dataset(print, (flags->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flags->left_just <= 0)
		dataset(print, str, 1);
}

void		printf_percent(t_pdata *print, t_pflag *flags, va_list args)
{
	field_proc(print, flags, args, NULL);
	purchent_data_process(print, flags, '%');
}
