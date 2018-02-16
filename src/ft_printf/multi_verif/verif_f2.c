/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_f2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:38:10 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 07:18:48 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline int	f2_a(t_pflag *flag, int *val, int read_flag)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (flag->precis_wild != -1 && flag->precis_wild == read_flag))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width_wild != -1 && flag->width_wild == read_flag))
	{
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
		return (1);
	}
	return (0);
}

static inline int	f2_b(t_pflag *flag, int *val, int read_flag)
{
	if ((flag->precis == 2 && flag->precis_wild != -1)
			&& (flag->width == 2 && flag->width_wild != -1)
			&& (flag->precis_wild == read_flag)
			&& (flag->width_wild == read_flag))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
		return (1);
	}
	else if ((flag->width == 0 && flag->width_wild == -1)
			&& (flag->precis_wild != -1 && flag->precis_wild == read_flag))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis = -1;
		flag->precis_wild = -1;
		return (1);
	}
	return (0);
}

static inline int	f2_c(t_pflag *flag, int *val, int read_flag, int *read)
{
	if ((flag->precis == 0 && flag->precis_wild == -1) && \
			(flag->width_wild != -1 && flag->width_wild == read_flag))
	{
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
		return (1);
	}
	else if ((flag->width == 2 && flag->width_wild == -1) && \
		(flag->precis_wild != -1 && flag->precis_wild == *read))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		return (1);
	}
	return (0);
}

static inline int	f2_d(t_pflag *flag, int *val, int *read)
{
	if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width_wild != -1 && flag->width_wild == *read))
	{
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild != -1)
			&& (flag->width == 2 && flag->width_wild != -1)
			&& (flag->precis_wild == flag->width_wild))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		return (1);
	}
	return (0);
}

int					verif_f2(t_pflag *flag, int *val, int *read)
{
	int	read_flag;

	if (flag->flag_arg == -1
			&& (flag->width_wild != -1 || flag->precis_wild != -1))
	{
		read_flag = *read + 1;
		if (f2_a(flag, val, read_flag) == 1)
			return (1);
		else if (f2_b(flag, val, read_flag) == 1)
			return (1);
		else if (f2_c(flag, val, read_flag, read) == 1)
			return (1);
		else if (f2_d(flag, val, read) == 1)
			return (1);
	}
	return (0);
}
