/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:07:22 by suddin            #+#    #+#             */
/*   Updated: 2019/11/19 00:22:38 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal_func.h"
#include "libft.h"

int	is_flag(t_uchar c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == 'X'
		|| c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G'
		|| c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'p' || c == 'n'
		|| c == '%' || c == 'b' || c == 'C' || c == 'S' || c == 'U' || c == 'D'
		|| c == 'O')
		return (1);
	else if (c == 'h' || c == 'l' || c == 'j' || c == 'z'
			|| c == 't' || c == 'L')
		return (2);
	else if (c == '-' || c == '+' || c == '#' || c == '.' || c == ' ' \
			|| c == '*' || ft_isdigit(c) || c == '\'' || c == '$')
		return (3);
	return (0);
}
