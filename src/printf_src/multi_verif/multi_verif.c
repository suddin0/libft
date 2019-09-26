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

#include "ft_printf.h"

/*
** Description:
** This function helps us initialize precision and width depending on their
** argument numbers. For an exemple if the argument chose for precision is the
** same as the width then it has to tell somehow that it souldn't call the same
** argument twice as it is not possible without a copy of va_list. So we just
** say , "Hey , those are the same values, so copy one of them later...".
**
**  Notice:
**  This version of multiverif is geniric. This function bust be used in all
**  type of flags.
**
**  Usage:
**  The function multi_verif(...) accepts 4 argument where if the ´void *f_val´
**  is the pointer to the flag it self(that we passed in argument) is a ´NULL´
**  then it will execute the first part of multi_verif. The first part of
**  multi_verif checks if a flag is assigned multiple times by a ´$´, if so then
**  it will do the necessery to not execite the while loop multiple times.
**  Tis way we can get arguments in one go.
**  To execute the second part of multi_verif the use must put a pointer in
**  in place of the third argument ´*f_val´ the se ond time multi_verif checkes
**  if any of the arguments ware sames if so then the values will be distributed
**  evenly among the one that was the same.
*/

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
