/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:53:36 by suddin            #+#    #+#             */
/*   Updated: 2018/01/23 08:54:40 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	simple_sort(int *array, int len)
{
	int	i;
	int	temp;

	i = 0;
	while (i != (len - 1))
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			if ((i - 1) >= 0)
				i--;
			continue;
		}
		i++;
	}
}
