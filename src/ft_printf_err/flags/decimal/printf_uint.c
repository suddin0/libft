/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 06:13:33 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 08:35:03 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_err.h"
#include "libft.h"

static void	set_num(t_pdata *print, t_pflag *flags, t_ullint dec)
{
	t_uchar	num[30];
	int		count;
	int		i;

	ft_memset(num, 0, 30);
	count = 0;
	i = 0;
	if (dec == 0)
		num[i++] = '0';
	while (dec > 0 && count++ > -1)
	{
		num[i++] = (dec % 10) + '0';
		if (count == 3 && flags->comma > 0 && (count = 0) > -1)
			num[i++] = ',';
		dec /= 10;
	}
	num[i] = 0;
	ft_strrev((char *)num);
	data_man(print, num, 0, i);
}

static void	right(t_pdata *print, t_pflag *flags, t_ullint dec)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;

	w = flags->width_val;
	p = flags->precis_val;
	dec_len = (dec == 0 && p == 0) ? 0 : cus_uuintlen(dec, flags->comma);
	tcpy = (p > dec_len) ? p : dec_len;
	if (tcpy < w && (flags->zero == 0 || p > -1))
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (flags->num_sign > 0)
		dataset(print, '+', 0);
	if (tcpy < w && flags->zero > 0 && p < 0)
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (p > 0 && p > dec_len)
		dataset(print, '0', p - dec_len);
	if (!(p == 0 && dec == 0))
		set_num(print, flags, dec);
}

static void	left(t_pdata *print, t_pflag *flags, t_ullint dec)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;

	w = flags->width_val;
	p = flags->precis_val;
	dec_len = cus_uuintlen(dec, flags->comma);
	tcpy = (p > dec_len) ? p : dec_len;
	if (p > dec_len)
		dataset(print, '0', p - dec_len);
	if (p == 0 && dec == 0)
		dataset(print, ' ', (w > 0) ? 1 : 0);
	else
		set_num(print, flags, dec);
	if (w > tcpy)
		dataset(print, ' ', w - tcpy);
}

static void	data_process(t_pdata *print, t_pflag *flags, t_llint dec)
{
	if (flags->left_just > 0)
		left(print, flags, dec);
	else
		right(print, flags, dec);
}

void		printf_uint(t_pdata *print, t_pflag *flags, va_list args)
{
	t_ullint	dec;

	dec = 0;
	dec = *((t_ullint *)field_proc(print, flags, args, (void *)arg_ullint));
	if (flags->length == 0)
		dec = (unsigned int)dec;
	else if (flags->length == 1)
		dec = (unsigned short)dec;
	else if (flags->length == 2)
		dec = (unsigned long int)dec;
	else if (flags->length == 3)
		dec = (uintmax_t)dec;
	else if (flags->length == 4)
		dec = (size_t)dec;
	else if (flags->length == 5)
		dec = (ptrdiff_t)dec;
	else if (flags->length == 6)
		dec = (unsigned long long int)dec;
	else if (flags->length == 7)
		dec = (unsigned char)dec;
	data_process(print, flags, dec);
}
