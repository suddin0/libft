/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:35:56 by suddin            #+#    #+#             */
/*   Updated: 2019/09/27 18:35:57 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

/*
** type represents the type of option (shirt or long).
** if 'type' (int type) :
**    0 : not a valide option
**    1 : short option
**    2 : long option
**
**
** First IF:
**    If there is only one character then it's not a valid option.
** ELSE IF:
**    If the option is the special case `--` the nsend a particular notification
*/

int	option_type(char *opt)
{
	int type;

	type = OPT_TYPE_NONE;
	if (!opt)
		return (OPT_TYPE_NONE);
	if (opt[type] == '-')
		type++;
	if (opt[type] == '-')
		type++;
	if (type == 1 && opt[type] == 0)
		return (OPT_TYPE_NONE);
	else if (type == 2 && opt[type] == 0)
		return (OPT_TYPE_END);
	if (type == 1)
		return (OPT_TYPE_SHORT);
	else if (type == 2)
		return (OPT_TYPE_LONG);
	else
		return (type);
}
