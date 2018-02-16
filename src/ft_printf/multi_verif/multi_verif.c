/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:26:01 by suddin            #+#    #+#             */
/*   Updated: 2018/01/25 07:30:09 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	va_tmp_init(int *val, int *read, int arg_n)
{
	val[4] = 0;
	val[5] = -1;
	val[6] = 0;
	val[7] = -1;
	val[8] = -1;
	val[9] = arg_n;
	*read = arg_n;
}

static int	verif_f(t_pflag *flag, int *val, int arg_n)
{
	int	read;

	read = 0;
	va_tmp_init(val, &read, arg_n);
	if (verif_f1(flag, val, &read) == 1)
		return (1);
	else if (verif_f2(flag, val, &read) == 1)
		return (1);
	else if (verif_f3(flag, val, arg_n) == 1)
		return (1);
	return (0);
}

static int	verif_l(t_pflag *flag, int *val, void *f_val, int arg_n)
{
	int	read;

	read = 0;
	if (verif_l1(flag, val, &read, f_val) == 1)
		return (1);
	else if (verif_l2(flag, val, &read, f_val) == 1)
		return (1);
	else if (verif_l3(flag, val, arg_n, f_val) == 1)
		return (1);
	return (0);
}

int			multi_verif(t_pflag *flag, int *val, void *f_val, int arg_n)
{
	if (f_val == NULL)
		return (verif_f(flag, val, arg_n));
	else if (f_val != NULL)
		return (verif_l(flag, val, f_val, val[9]));
	else
		return (0);
}
