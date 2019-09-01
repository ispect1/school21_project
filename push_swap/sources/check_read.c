/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 03:40:32 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/19 14:52:20 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int ac, char **av)
{
	int i;

	while (ac >= 0)
	{
		i = 0;
		while (av[ac][i])
		{
			if (!(av[ac][i] == ' ' || (av[ac][i] <= '9' && av[ac][i] >= '0')
			|| av[ac][i] == '-' || av[ac][i] == '+'))
				return (-1);
			i++;
		}
		ac--;
	}
	return (1);
}

int	*reader(int ac, char **av)
{
	int *k;
	int i;

	i = 0;
	k = (int*)ft_memalloc(sizeof(*k) * (ac + 1));
	while (ac >= 0)
	{
		k[i] = ft_atoll(av[ac]);
		i++;
		ac--;
	}
	return (k);
}

int	determ_pivot(int *a, int n, int truelen)
{
	int tmp[n];

	ft_memcpy(tmp, a + truelen - n, 4 * n);
	quick_sort(tmp, n);
	return (tmp[n / 2]);
}

int	check_copie(int *a, int len)
{
	int tmp[len];

	ft_memcpy(tmp, a, 4 * len);
	quick_sort(tmp, len);
	while (--len > 0)
		if (tmp[len] <= tmp[len - 1])
			return (0);
	return (1);
}
