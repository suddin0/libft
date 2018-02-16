/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 06:40:15 by suddin            #+#    #+#             */
/*   Updated: 2018/02/01 10:03:34 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	right_extra(t_pdata *print, t_pflag *flags, t_ullint dec, char type)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;
	int	fsign;

	fsign = flags->flag_sign;
	w = flags->width_val;
	p = flags->precis_val;
	flags->comma = get_num_base(fsign);
	dec_len = cus_num_intlen(dec, flags->comma);
	tcpy = ((p > dec_len) ? p : dec_len) + type;
	if (tcpy < w && flags->zero > 0 && p < 0)
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (p > 0 && p > dec_len)
		dataset(print, '0', p - dec_len);
	if (p == 0 && dec == 0 && flags->comma == 16)
		dataset(print, ' ', (w > 0) ? 1 : 0);
	else if (p == 0 && dec == 0 && flags->comma == 8 && w <= 0)
		dataset(print, '0', (flags->num_type > 0) ? 1 : 0);
	else if (p == 0 && dec == 0 && flags->comma == 8 && w > 0)
		dataset(print, ' ', 1);
	else
		set_num_base(print, dec, flags->comma, (fsign > 91) ? 32 : 0);
}

static void	right(t_pdata *print, t_pflag *flags, t_ullint dec, char type)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;
	int	fsign;

	fsign = flags->flag_sign;
	w = flags->width_val;
	p = flags->precis_val;
	flags->comma = get_num_base(fsign);
	dec_len = cus_num_intlen(dec, flags->comma);
	tcpy = ((p > dec_len) ? p : dec_len) + type;
	if (tcpy < w && (flags->zero == 0 || p > -1))
		dataset(print, (flags->zero > 0 && p < 0) ? '0' : ' ', w - tcpy);
	if (type > 0)
	{
		if (flags->comma == 16)
		{
			dataset(print, '0', 1);
			dataset(print, (fsign < 95) ? 'X' : 'x', 1);
		}
		else
			dataset(print, '0', (p > dec_len) ? 0 : 1);
	}
	right_extra(print, flags, dec, type);
}

static void	left(t_pdata *print, t_pflag *flags, t_ullint dec, char type)
{
	int	w;
	int	p;
	int	dec_len;
	int	tcpy;

	w = flags->width_val;
	p = flags->precis_val;
	flags->comma = get_num_base(flags->flag_sign);
	dec_len = cus_num_intlen(dec, get_num_base(flags->flag_sign));
	tcpy = ((p > dec_len) ? p : dec_len) + type;
	if (type > 0)
	{
		dataset(print, '0', 1);
		if (flags->comma == 16)
			dataset(print, (flags->flag_sign < 95) ? 'X' : 'x', 1);
	}
	if (p > dec_len)
		dataset(print, '0', p - dec_len);
	if (p == 0 && dec == 0)
		dataset(print, ' ', (w > 0) ? 1 : 0);
	else
		set_num_base(print, dec, flags->comma, (flags->flag_sign > 91) ? 1 : 0);
	if (w > tcpy)
		dataset(print, ' ', w - tcpy);
}

static void	data_process(t_pdata *print, t_pflag *flags, t_llint dec)
{
	char	type;

	type = 2;
	flags->flag_sign = 'x';
	if (flags->left_just > 0)
		left(print, flags, dec, type);
	else
		right(print, flags, dec, type);
}

void		printf_pointer(t_pdata *print, t_pflag *flags, va_list args)
{
	t_ullint	dec;

	dec = 0;
	dec = *((t_lint *)field_proc(print, flags, args, (void *)arg_llint));
	data_process(print, flags, dec);
}
