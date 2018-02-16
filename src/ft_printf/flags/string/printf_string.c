/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 04:22:39 by suddin            #+#    #+#             */
/*   Updated: 2018/01/27 23:45:38 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	str_data_process(t_pdata *print, t_pflag *flags, char *str)
{
	int	total;
	int	to_copy;
	int	str_len;
	int	a;

	a = flags->precis_val;
	str_len = ft_strlen(str);
	to_copy = (a < str_len && a != -1) ? a : str_len;
	total = (flags->width_val > to_copy) ? flags->width_val : to_copy;
	a = flags->left_just;
	if (a > 0)
		data_man(print, (t_uchar *)str, 0, to_copy);
	dataset(print, (flags->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flags->left_just <= 0)
		data_man(print, (t_uchar *)str, 0, to_copy);
}

void		printf_string(t_pdata *print, t_pflag *flags, va_list args)
{
	char	*str;

	str = NULL;
	if (flags->length == 2)
	{
		printf_wchars(print, flags, args);
		return ;
	}
	str = (char *)field_proc(print, flags, args, (void *)arg_str);
	str_data_process(print, flags, (str == NULL) ? "(null)" : str);
}
