/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:43:18 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 08:32:16 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline int	l2_a(t_pflag *flag, int *val, int read_flag, int32_t *f_val)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (val[5] != -1 && val[5] == read_flag))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = *f_val;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (val[7] != -1 && val[7] == read_flag))
	{
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = *f_val;
		return (1);
	}
	return (0);
}

static inline int	l2_b(t_pflag *flag, int *val, int read_flag, int32_t *f_val)
{
	if ((val[4] == 2 && val[5] != -1) && (val[6] == 2 && val[7] != -1)
			&& (val[5] == read_flag) && (val[7] == read_flag))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = *f_val;
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = *f_val;
		return (1);
	}
	else if ((flag->width == 0 && flag->width_wild == -1)
			&& (val[4] != -1 && val[5] == read_flag))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = *f_val;
		return (1);
	}
	return (0);
}

static inline int	l2_c(t_pflag *flag, int *val, int *read, int32_t *flag_val)
{
	if ((flag->precis == 0 && flag->precis_wild == -1)
			&& (val[6] != -1 && val[7] == *read + 1))
	{
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = *flag_val;
		return (1);
	}
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (val[5] != -1 && val[5] == *read))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = flag->width_val;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (val[7] != -1 && val[7] == *read))
	{
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = flag->precis_val;
		return (1);
	}
	return (0);
}

int					verif_l2(t_pflag *flag, int *val, int *read, int32_t *f_val)
{
	int		read_flag;
	int32_t	*flag_val;

	flag_val = (int32_t *)f_val;
	if (flag->flag_arg == -1 && ((flag->width_wild != -1
				|| flag->precis_wild != -1) || (val[7] != -1 || val[5] != -1)))
	{
		read_flag = *read + 1;
		if (l2_a(flag, val, read_flag, flag_val) == 1)
			return (1);
		else if (l2_b(flag, val, read_flag, flag_val) == 1)
			return (1);
		else if (l2_c(flag, val, read, flag_val) == 1)
			return (1);
		else if ((val[4] == 2 && val[5] != -1) && (val[5] == flag->width_wild)
				&& (flag->width == 2 && flag->width_wild != -1))
		{
			flag->precis = val[4];
			flag->precis_wild = val[5];
			flag->precis_val = flag->width_val;
			return (1);
		}
	}
	return (0);
}
