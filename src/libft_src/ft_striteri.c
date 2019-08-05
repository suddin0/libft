/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:22:10 by suddin            #+#    #+#             */
/*   Updated: 2017/04/24 10:48:12 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*v;

	if (!s || !f)
		return ;
	i = 0;
	v = s;
	while (*v != '\0')
	{
		f(i, v);
		i++;
		v++;
	}
}