/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 04:32:57 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 09:51:42 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

static void	right(t_pdata *print, t_pflag *flags, t_llint dec, char space)
{
	int	w;
	int	p;
	int	dec_len;
	int	n_sig;
	int	tcpy;

	w = flags->width_val - space;
	p = flags->precis_val;
	n_sig = (flags->num_sign || dec < 0) ? 1 : 0;
	dec_len = (dec == 0 && p == 0) ? 0 : cus_iintlen(dec, flags->comma);
	tcpy = dec_len + ((dec < 0) ? 0 : n_sig);
	tcpy = ((p + n_sig) > dec_len) ? p + n_sig : tcpy;
	if (tcpy < w && (flags->zero == 0 || p > -1))
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (dec < 0 || flags->num_sign > 0)
		dataset(print, (dec < 0) ? '-' : '+', 1);
	if (tcpy < w && flags->zero > 0 && p < 0)
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	n_sig = (dec < 0) ? 1 : 0;
	if ((p + n_sig) > 0 && (p + n_sig) > dec_len)
		dataset(print, '0', (p + n_sig) - dec_len);
	if (!(p == 0 && dec == 0))
		set_num(print, flags, (dec < 0) ? -dec : dec);
}

static void	left(t_pdata *print, t_pflag *flags, t_llint dec, char space)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;
	int	n_sig;

	w = flags->width_val - space;
	p = flags->precis_val;
	n_sig = flags->num_sign;
	dec_len = cus_iintlen(dec, flags->comma);
	if (p + n_sig > dec_len)
		tcpy = p + n_sig;
	else
		tcpy = dec_len + ((dec < 0) ? 0 : n_sig);
	if (dec < 0 || flags->num_sign > 0)
		dataset(print, (dec < 0) ? '-' : '+', 1);
	if (p > ((dec < 0L) ? (dec_len - 1) : dec_len))
		dataset(print, '0', p - ((dec < 0L) ? (dec_len - 1) : dec_len));
	if (p == 0 && dec == 0)
		dataset(print, ' ', (w > 0) ? 1 : 0);
	else
		set_num(print, flags, ((dec < 0) ? -dec : dec));
	if (w > tcpy)
		dataset(print, ' ', w - tcpy);
}

static void	data_process(t_pdata *print, t_pflag *flags, t_llint dec)
{
	char	space;

	space = 0;
	if (flags->space > 0 && flags->num_sign < 1 && dec > -1)
	{
		dataset(print, ' ', 1);
		space = 1;
	}
	if (flags->left_just > 0)
		left(print, flags, dec, space);
	else
		right(print, flags, dec, space);
}

void		printf_int(t_pdata *print, t_pflag *flags, va_list args)
{
	t_llint	dec;

	dec = 0;
	dec = *((t_llint *)field_proc(print, flags, args, (void *)arg_llint));
	if (flags->length == 0)
		dec = (int)dec;
	else if (flags->length == 1)
		dec = (short)dec;
	else if (flags->length == 7)
		dec = (char)dec;
	data_process(print, flags, dec);
}
