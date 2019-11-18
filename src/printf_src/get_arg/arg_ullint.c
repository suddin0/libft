/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ullint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:20:16 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:20:48 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"

t_ullint	*arg_ullint(int *read, int arg_num, t_pdata *print, va_list args)
{
	static unsigned long long int	i[2];

	i[0] = 0;
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		i[0] = va_arg(args, unsigned long long int);
		return (i);
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	i[0] = va_arg(args, unsigned long long int);
	return (i);
}
