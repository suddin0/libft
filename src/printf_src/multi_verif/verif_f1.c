/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_f1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:30:31 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 06:35:36 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	is_width_or_precis(t_pflag *flag, int *read)
{
	if (flag->precis == 2 && flag->precis_wild == -1 && flag->width_wild != -1)
		(*read)++;
	else if (flag->width == 2 && flag->width_wild == -1
			&& flag->precis_wild != -1)
		(*read)++;
}

static inline int	f1_a(t_pflag *flag, int *val, int *read)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (flag->precis_wild != -1 && flag->precis_wild == *read)
			&& (flag->flag_arg != -1 && flag->flag_arg_val == *read))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		val[3] = 1;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width_wild != -1 && flag->width_wild == *read)
			&& (flag->flag_arg != -1 && flag->flag_arg_val == *read))
	{
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width = -1;
		flag->width_wild = -1;
		val[3] = 1;
		return (1);
	}
	return (0);
}

static inline int	f1_b(t_pflag *flag, int *val)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (flag->precis_wild != -1 && flag->flag_arg != -1)
			&& (flag->precis_wild == flag->flag_arg_val))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (flag->width_wild != -1 && flag->flag_arg != -1)
			&& (flag->width_wild == flag->flag_arg_val))
	{
		val[6] = flag->width;
		val[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
		return (1);
	}
	return (0);
}

static inline int	f1_c(t_pflag *flag, int *val)
{
	if ((flag->precis == 2 && flag->precis_wild != -1)
			&& (flag->width == 2 && flag->width_wild != -1) &&
			(flag->flag_arg != -1) && (flag->width_wild == flag->flag_arg_val)
			&& (flag->precis_wild == flag->flag_arg_val))
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
			&& (flag->precis_wild != -1 && flag->flag_arg != -1)
			&& (flag->precis_wild == flag->flag_arg_val))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = -1;
		return (1);
	}
	return (0);
}

int					verif_f1(t_pflag *flag, int *val, int *read)
{
	is_width_or_precis(flag, read);
	if (flag->flag_arg != -1 && (flag->width_wild != -1
				|| flag->precis_wild != -1))
	{
		if (f1_a(flag, val, read) == 1)
			return (1);
		else if (f1_b(flag, val) == 1)
			return (1);
		else if (f1_c(flag, val) == 1)
		{
			flag->precis = -1;
			return (1);
		}
		else if ((flag->precis == 0 && flag->precis_wild == -1)
				&& (flag->width_wild != -1 && flag->flag_arg != -1)
				&& (flag->width_wild == flag->flag_arg_val))
		{
			val[6] = flag->width;
			val[7] = flag->width_wild;
			flag->width_wild = -1;
			flag->width = -1;
			return (1);
		}
	}
	return (0);
}
