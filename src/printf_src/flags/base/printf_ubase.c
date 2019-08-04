/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ubase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 06:48:01 by suddin            #+#    #+#             */
/*   Updated: 2018/01/27 13:10:14 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	set_num(t_pdata *print, t_ullint dec, t_uchar base, t_uchar cap)
{
	char	num[33];
	int		i;

	i = 0;
	ft_memset(num, 0, 33);
	if (dec == 0)
		num[i++] = '0';
	if (cap == 0)
		while (dec != 0)
		{
			num[i++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[dec % base];
			dec /= base;
		}
	else
		while (dec != 0)
		{
			num[i++] = "0123456789abcdefghijklmnopqrstuvwzyz"[dec % base];
			dec /= base;
		}
	ft_strrev(num);
	data_man(print, (t_uchar *)num, 0, i);
}

static void	right(t_pdata *print, t_pflag *flags, t_llint dec, char type)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;
	int	fsign;

	fsign = flags->flag_sign;
	w = flags->width_val;
	p = flags->precis_val;
	dec_len = cus_uintlen(dec, 8);
	tcpy = ((p > dec_len) ? p : dec_len) + type;
	if (tcpy < w && (flags->zero == 0 || p > -1))
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (type > 0)
		dataset(print, '0', 1);
	if (tcpy < w && flags->zero > 0 && p < 0)
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (p > 0 && p > dec_len)
		dataset(print, '0', p - dec_len);
	if (p == 0 && dec == 0 && w <= 0)
		dataset(print, '0', (flags->num_type > 0) ? 1 : 0);
	else if (p == 0 && dec == 0 && w > 0)
		dataset(print, ' ', 1);
	else
		set_num(print, dec, 8, (fsign > 91) ? 32 : 0);
}

static void	left(t_pdata *print, t_pflag *flags, t_llint dec, char type)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;
	int	fsign;

	fsign = flags->flag_sign;
	w = flags->width_val;
	p = flags->precis_val;
	dec_len = cus_uintlen(dec, 8);
	tcpy = ((p > dec_len) ? p : dec_len) + type;
	if (type > 0)
	{
		dataset(print, '0', 1);
		tcpy -= 1;
	}
	if (p > dec_len)
		dataset(print, '0', p - dec_len);
	if (p == 0 && dec == 0)
		dataset(print, ' ', (w > 0) ? 1 : 0);
	else
		set_num(print, dec, 8, (fsign > 91) ? 32 : 0);
	if (w > tcpy)
		dataset(print, ' ', w - tcpy);
}

static void	data_process(t_pdata *print, t_pflag *flags, t_llint dec)
{
	char	type;

	type = 0;
	if (flags->num_type > 0 && dec != 0)
		type = 1;
	if (flags->left_just > 0)
		left(print, flags, dec, type);
	else
		right(print, flags, dec, type);
}

void		printf_ubase(t_pdata *print, t_pflag *flags, va_list args)
{
	t_llint	dec;

	dec = 0;
	dec = *((t_lint *)field_proc(print, flags, args, (void *)arg_llint));
	data_process(print, flags, dec);
}
