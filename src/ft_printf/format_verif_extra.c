/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:30:34 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 09:30:37 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int					check_flag(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start;
	while (str[i] && i != end)
	{
		if (str[i] == '-')
			flag->left_just = 1;
		else if (str[i] == '+')
			flag->num_sign = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (str[i] == '#')
			flag->num_type = 1;
		else if (str[i] == '0')
			flag->zero = 1;
		else if (str[i] == 39)
			flag->comma = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

static inline int	ch_width_extra(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start;
	flag->width = 2;
	i++;
	if (ft_isdigit(str[i]))
	{
		flag->width_wild = 0;
		flag->width_val = 0;
		while (i < end && ft_isdigit(str[i]))
		{
			flag->width_wild = (flag->width_wild * 10) + (str[i] - '0');
			i++;
		}
		if (str[i] == '$')
			return (i + 1);
		flag->width_wild = -1;
		flag->width_val = -1;
		return (-1);
	}
	return (i);
}

int					check_width(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start;
	if (str[i] == '*')
		return (ch_width_extra(flag, str, start, end));
	flag->width_val = 0;
	while (i < end && ft_isdigit(str[i]))
	{
		flag->width_val = (flag->width_val * 10) + (str[i] - '0');
		i++;
	}
	if (i != start)
		flag->width = 1;
	else
		flag->width_val = -1;
	return (i);
}

static inline int	ch_prcs_extra(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start + 2;
	flag->precis = 2;
	if (ft_isdigit(str[i]))
	{
		flag->precis_wild = 0;
		flag->precis_val = 0;
		while (i < end && ft_isdigit(str[i]))
		{
			flag->precis_wild = (flag->precis_wild * 10) + str[i] - 48;
			i++;
		}
		if (str[i] == '$')
			return (i + 1);
		flag->precis_wild = -1;
		flag->precis_val = -1;
		return (-1);
	}
	return (i);
}

int					check_precis(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start;
	if (str[i] == '.')
	{
		i++;
		if (str[i] == '*')
			return (ch_prcs_extra(flag, str, start, end));
		flag->precis_val = 0;
		while (ft_isdigit(str[i]) && i < end)
		{
			flag->precis_val = (flag->precis_val * 10) + (str[i] - '0');
			i++;
		}
		if (i != start)
			flag->precis = 1;
		else
			flag->precis_val = -1;
	}
	return (i);
}
