/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:16:09 by ljonnel-          #+#    #+#             */
/*   Updated: 2018/12/21 21:16:10 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *ar, int size)
{
	int i;
	int max;

	max = ar[0];
	i = 1;
	while (i < size)
	{
		if (ar[i] > max)
			max = ar[i];
		i++;
	}
	return (max);
}