/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wcharc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:23:12 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 09:06:52 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	w_to_charc(wchar_t c, t_pdata *print)
{
	if (c < (1 << 7))
		dataset(print, (unsigned char)(c), 1);
	else if (c < (1 << 11))
	{
		dataset(print, (unsigned char)((c >> 6) | 0xC0), 1);
		dataset(print, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
	else if (c < (1 << 16))
	{
		dataset(print, (unsigned char)(((c >> 12)) | 0xE0), 1);
		dataset(print, (unsigned char)(((c >> 6) & 0x3F) | 0x80), 1);
		dataset(print, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
	else if (c < (1 << 21))
	{
		dataset(print, (unsigned char)(((c >> 18)) | 0xF0), 1);
		dataset(print, (unsigned char)(((c >> 12) & 0x3F) | 0x80), 1);
		dataset(print, (unsigned char)(((c >> 6) & 0x3F) | 0x80), 1);
		dataset(print, (unsigned char)((c & 0x3F) | 0x80), 1);
	}
}

static int	wcharc_len(wchar_t str)
{
	if (str < (1 << 7))
		return (1);
	else if (str < (1 << 11))
		return (2);
	else if (str < (1 << 16))
		return (3);
	else
		return (4);
}

static void	char_data_process(t_pdata *print, t_pflag *flags, wchar_t str)
{
	int total;
	int to_copy;
	int a;

	to_copy = wcharc_len(str);
	total = (flags->width_val > to_copy) ? flags->width_val : to_copy;
	a = flags->left_just;
	if (a > 0)
		w_to_charc(str, print);
	dataset(print, (flags->zero > 0 && a == 0) ? '0' : ' ', total - to_copy);
	if (flags->left_just <= 0)
		w_to_charc(str, print);
}

void		printf_wcharc(t_pdata *print, t_pflag *flags, va_list args)
{
	wchar_t c;

	c = 0;
	c = *((wchar_t *)field_proc(print, flags, args, (void *)arg_wcharc));
	char_data_process(print, flags, (c == 0) ? 0 : c);
}
