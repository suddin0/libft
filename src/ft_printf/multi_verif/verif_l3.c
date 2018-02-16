/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_l3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:44:31 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 08:45:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	width_n_precis(t_pflag *flag, int arg_n, int *prec, int *wi)
{
	if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width == 2 && flag->precis_wild == -1))
	{
		*wi = arg_n + 1;
		*prec = *wi + 1;
	}
}

static inline int	l3_a(t_pflag *flag, int *val, int arg_n, int32_t *f_val)
{
	if (val[8] != -1
			&& (flag->width < 2 && flag->width_wild == -1)
			&& (flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->flag_arg_val == arg_n + 1))
	{
		*f_val = flag->precis_val;
		flag->flag_arg = val[8];
		return (flag->precis_val);
	}
	else if (val[8] != -1
			&& (flag->precis < 2 && flag->precis_wild == -1)
			&& (flag->width == 2 && flag->width_wild == -1)
			&& (flag->flag_arg_val == arg_n + 1))
	{
		*f_val = flag->width_val;
		flag->flag_arg = val[8];
		return (flag->width_val);
	}
	return (0);
}

int					verif_l3(t_pflag *flag, int *val, int arg_n, int32_t *f_val)
{
	int	prec;
	int	wid;

	prec = 0;
	wid = 0;
	if (val[8] != -1 && (flag->width == 2 && flag->width_wild == -1)
			&& (flag->precis == 2 && flag->precis_wild == -1))
	{
		width_n_precis(flag, arg_n, &prec, &wid);
		if (flag->flag_arg_val == wid)
		{
			*f_val = flag->width_val;
			flag->flag_arg = val[8];
			return (flag->width_val);
		}
		else if (flag->flag_arg_val == prec)
		{
			*f_val = flag->precis_val;
			flag->flag_arg = val[8];
			return (flag->precis_val);
		}
	}
	else if (l3_a(flag, val, arg_n, f_val))
		return (l3_a(flag, val, arg_n, f_val));
	return (0);
}
