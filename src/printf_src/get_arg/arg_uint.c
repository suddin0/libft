/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 07:18:30 by suddin            #+#    #+#             */
/*   Updated: 2018/01/25 07:19:08 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_uint	*arg_uint(int *read, int arg_num, t_pdata *print, va_list args)
{
	static unsigned int	i[2];

	i[0] = 0;
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		i[0] = va_arg(args, unsigned int);
		return (i);
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	i[0] = va_arg(args, unsigned int);
	return (i);
}
