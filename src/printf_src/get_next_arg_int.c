/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 21:05:08 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:22:30 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

int	get_next_int(int *read, int arg_num, t_pdata *print, va_list args)
{
	int i;

	i = 0;
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		i = va_arg(args, int);
		return ((i < 0) ? 0 : i);
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	i = va_arg(args, int);
	return ((i < 0) ? 0 : i);
}
