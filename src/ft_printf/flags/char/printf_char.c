/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 04:14:44 by suddin            #+#    #+#             */
/*   Updated: 2018/01/25 04:18:23 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	char_data_process(t_pdata *print, t_pflag *flags, int str)
{
	int	total;
	int	to_copy;
	int	a;

	to_copy = 1;
	total = (flags->width_val > to_copy) ? flags->width_val : to_copy;
	a = flags->left_just;
	if (a > 0)
		dataset(print, str, 1);
	dataset(print, (flags->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flags->left_just <= 0)
		dataset(print, str, 1);
}

void		printf_char(t_pdata *print, t_pflag *flags, va_list args)
{
	int	c;

	c = 0;
	if (flags->length == 2)
	{
		printf_wcharc(print, flags, args);
		return ;
	}
	c = *((t_uint *)field_proc(print, flags, args, (void *)arg_uint));
	char_data_process(print, flags, (c == 0) ? 0 : c);
}
