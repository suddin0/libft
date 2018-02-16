/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 20:52:02 by suddin            #+#    #+#             */
/*   Updated: 2018/01/26 09:59:13 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	check_flag_arg(t_pflag *flag, char *str, int start, int end)
{
	int	i;

	i = start;
	if (ft_isdigit(str[i]) && str[i] != '0')
	{
		flag->flag_arg_val = 0;
		while (i != end && ft_isdigit(str[i]))
		{
			flag->flag_arg_val = (flag->flag_arg_val * 10) + (str[i] - '0');
			i++;
		}
		if (str[i] == '$')
		{
			flag->flag_arg = 1;
			return (i + 1);
		}
		else
			flag->flag_arg_val = -1;
	}
	return (start);
}

static int	check_lenth(t_pflag *flag, char *str, int start)
{
	int i;
	int j;
	int arr_len;

	i = start;
	j = -1;
	arr_len = 6;
	if (str[i + 1])
	{
		if (str[i] == 'h' && str[i + 1] == 'h' && (flag->length = 7) > 0)
			return (i + 2);
		else if (str[i] == 'l' && str[i + 1] == 'l' && (flag->length = 6) > 0)
			return (i + 2);
	}
	if (str[i] == 'h' || str[i] == 'j' || str[i] == 'l' || str[i] == 'L' || \
			str[i] == 't' || str[i] == 'z')
	{
		while (++j < arr_len)
			if ("\x7fhljztL\0"[j] == str[i])
				flag->length = j;
		return (++i);
	}
	return (i);
}

static void	format_init(int *j, int *arr_len)
{
	*j = -1;
	*arr_len = 26;
}

int			format_verif(t_pflag *flag, char *str, int start, int end)
{
	int i;
	int j;
	int arr_len;

	i = start;
	format_init(&j, &arr_len);
	i = check_flag_arg(flag, str, i, end);
	i = check_flag(flag, str, i, end);
	i = check_width(flag, str, i, end);
	i = check_precis(flag, str, i, end);
	i = check_lenth(flag, str, i);
	if (is_flag(str[i]) == 1)
	{
		while (++j < arr_len)
			if (str[i] == "scdp%nuoOxXiUDCS"[j])
			{
				(flag)->flag = j;
				flag->flag_sign = str[i];
				break ;
			}
		flag->nstart = (i - start) + 1;
		return (1);
	}
	flag->nstart = i - start;
	return (0);
}
