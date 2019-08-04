/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_l1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:41:23 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 08:10:59 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static inline void	is_width_or_precis(t_pflag *flag, int *val, int *read)
{
	if (flag->precis == 2 && flag->precis_wild == -1 && val[7] != -1)
	{
		(*read)++;
	}
	else if (flag->width == 2 && flag->width_wild == -1 && val[5] != -1)
		(*read)++;
}

static inline int	l1_a(t_pflag *flag, int *val, int *read, int32_t *f_val)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (val[5] != -1 && val[5] == *read)
			&& (flag->flag_arg != -1 && flag->flag_arg_val == *read))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = flag->width_val;
		*f_val = flag->width_val;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (val[7] != -1 && val[7] == *read)
			&& (flag->flag_arg != -1 && flag->flag_arg_val == *read))
	{
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = flag->precis_val;
		*f_val = flag->precis_val;
		return (1);
	}
	return (0);
}

static inline int	l1_b(t_pflag *flag, int *val, int32_t *flag_val)
{
	if ((flag->width == 2 && flag->width_wild == -1)
			&& (val[5] != -1 && flag->flag_arg != -1)
			&& (val[5] == flag->flag_arg_val))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = *flag_val;
		return (1);
	}
	else if ((flag->precis == 2 && flag->precis_wild == -1)
			&& (val[7] != -1 && flag->flag_arg != -1)
			&& (val[7] == flag->flag_arg_val))
	{
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = *flag_val;
		return (1);
	}
	return (0);
}

static inline int	l1_c(t_pflag *flag, int *val, int32_t *flag_val)
{
	if ((val[4] == 2 && val[5] != -1) && (val[6] == 2 && val[7] != -1)
			&& (flag->flag_arg != -1) && (val[7] == flag->flag_arg_val)
			&& (val[5] == flag->flag_arg_val))
	{
		flag->precis = val[4];
		flag->precis_wild = val[5];
		flag->precis_val = *flag_val;
		flag->width = val[6];
		flag->width_wild = val[7];
		flag->width_val = *flag_val;
		return (1);
	}
	else if ((flag->width == 0 && flag->width_wild == -1)
			&& (val[5] != -1 && flag->flag_arg != -1)
			&& (val[5] == flag->flag_arg_val))
	{
		val[4] = flag->precis;
		val[5] = flag->precis_wild;
		flag->precis_wild = *flag_val;
		flag->precis_val = *flag_val;
		return (1);
	}
	return (0);
}

int					verif_l1(t_pflag *flag, int *val, int *read, int32_t *f_val)
{
	int32_t	*flag_val;

	flag_val = (int32_t *)f_val;
	is_width_or_precis(flag, val, read);
	if (flag->flag_arg != -1 && (val[7] != -1 || val[5] != -1))
	{
		if (l1_a(flag, val, read, f_val) == 1)
			return (1);
		else if (l1_b(flag, val, flag_val) == 1)
			return (1);
		else if (l1_c(flag, val, flag_val) == 1)
			return (1);
		else if ((flag->precis == 0 && flag->precis_wild == -1)
				&& (val[7] != -1 && flag->flag_arg != -1)
				&& (val[7] == flag->flag_arg_val))
		{
			val[6] = flag->width;
			val[7] = flag->width_wild;
			flag->width_wild = *flag_val;
			flag->width_val = *flag_val;
			return (1);
		}
	}
	return (0);
}
