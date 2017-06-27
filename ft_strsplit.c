/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <suddin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 01:46:33 by suddin            #+#    #+#             */
/*   Updated: 2017/04/24 11:24:06 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int			count_word(char *str, char c)
{
	int mot;
	int i;

	mot = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			if (str[i + 1] == c || str[i + 1] == '\0')
				mot++;
		i++;
	}
	return (mot);
}

static	void		*auto_alloc(char *str, char **tab, char c)
{
	int t;
	int i;
	int count;

	t = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				tab[t] = ft_strnew(count + 2);
				if (tab[t] == NULL)
					return (NULL);
				t++;
				count = 0;
			}
		}
		i++;
	}
	return (tab);
}

static	void		fill_array(char *str, char **tab, char c)
{
	int t;
	int v;
	int i;

	t = 0;
	i = 0;
	v = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			tab[t][v] = str[i];
			v++;
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				tab[t][v] = '\0';
				t++;
				v = 0;
			}
		}
		i++;
	}
	tab[t] = 0;
}

char				**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if (auto_alloc((char *)s, tab, c) == NULL)
		return (NULL);
	fill_array((char *)s, tab, c);
	return (tab);
}
