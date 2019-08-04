/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:32:28 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 09:52:36 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	flag_init(t_pflag *flag)
{
	flag->left_just = 0;
	flag->num_sign = 0;
	flag->space = 0;
	flag->num_type = 0;
	flag->zero = 0;
	flag->comma = 0;
	flag->width = 0;
	flag->width_wild = -1;
	flag->width_val = -1;
	flag->precis = 0;
	flag->precis_wild = -1;
	flag->precis_val = -1;
	flag->length = 0;
	flag->flag = 0;
	flag->flag_arg = -1;
	flag->flag_arg_val = -1;
	flag->nstart = -1;
}

int			flag_man(t_pdata *print, t_ppnt *temp, char *str, va_list args)
{
	t_pflag	flag[1];

	flag_init(flag);
	if (format_verif(flag, str, temp->start + 1, temp->i) == 1)
	{
		data_man(print, (t_uchar *)str, print->tstart, temp->start);
		print->tstart = (temp->start) + flag[0].nstart + 1;
		(temp->func)[(int)flag->flag](print, flag, args);
		temp->flag1 = 0;
	}
	else
	{
		data_man(print, (t_uchar *)str, print->tstart, temp->start);
		print->tstart = (temp->start + 1) + flag[0].nstart;
	}
	temp->flag1 = 0;
	return (0);
}
