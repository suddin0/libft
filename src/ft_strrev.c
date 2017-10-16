/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 02:58:40 by suddin            #+#    #+#             */
/*   Updated: 2017/04/20 02:58:47 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		tt;
	int		pp;

	pp = 0;
	tt = 0;
	while (str[tt] != '\0')
		tt++;
	tt -= 1;
	while (tt > pp)
	{
		tmp = str[pp];
		str[pp] = str[tt];
		str[tt] = tmp;
		tt--;
		pp++;
	}
	return (str);
}
