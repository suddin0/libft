/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_f3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:39:59 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 07:50:58 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	width_n_precis(t_pflag *flag, int arg_n, int *pr, int *wid)
{
	if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width == 2 && flag->precis_wild == -1))
	{
		*wid = arg_n + 1;
		*pr = *wid + 1;
	}
}

static inline int	f3_a(t_pflag *flag, int *val, int wid, int prec)
{
	if (flag->flag_arg_val == wid)
	{
		val[3] = 1;
		val[8] = flag->flag_arg;
		flag->flag_arg = -1;
		return (1);
	}
	else if (flag->flag_arg_val == prec)
	{
		val[3] = 1;
		val[8] = flag->flag_arg;
		flag->flag_arg = -1;
		return (1);
	}
	return (0);
}

static inline int	f3_b(t_pflag *flag, int *val, int arg_n)
{
	if (flag->flag_arg != -1
			&& (flag->width < 2 && flag->width_wild == -1)
			&& (flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->flag_arg_val == arg_n + 1))
	{
		val[3] = 1;
		val[8] = flag->flag_arg;
		flag->flag_arg = -1;
		return (1);
	}
	else if (flag->flag_arg != -1
			&& (flag->precis < 2 && flag->precis_wild == -1)
			&& (flag->width == 2 && flag->width_wild == -1)
			&& (flag->flag_arg_val == arg_n + 1))
	{
		val[3] = 1;
		val[8] = flag->flag_arg;
		flag->flag_arg = -1;
		return (1);
	}
	return (0);
}

int					verif_f3(t_pflag *flag, int *val, int arg_n)
{
	int	prec;
	int	wid;

	prec = 0;
	wid = 0;
	if (flag->flag_arg != -1
			&& (flag->width == 2 && flag->width_wild == -1)
			&& (flag->precis == 2 && flag->precis_wild == -1))
	{
		width_n_precis(flag, arg_n, &prec, &wid);
		if (f3_a(flag, val, wid, prec) == 1)
			return (1);
	}
	else if (f3_b(flag, val, arg_n) == 1)
		return (1);
	return (0);
}
