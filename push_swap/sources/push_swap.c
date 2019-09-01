/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:06:09 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/11 12:06:12 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		pos_min(int *a, int len)
{
	int min;
	int pos;
	int i;

	min = a[0];
	pos = 0;
	i = 1;
	while (i < len)
	{
		if (a[i] < min)
		{
			min = a[i];
			pos = i;
		}
		i++;
	}
	return (pos + 1);
}

void	sort_less_10_dop(t_stack *stack, int *a)
{
	int len;

	if (a[stack->alen - 2] == ft_min(a, stack->alen) && a[stack->alen - 1]
	< determ_pivot(a, stack->alen, stack->alen))
	{
		ps_s(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'b', 1);
	}
	else if ((len = pos_min(a, stack->alen)) <= stack->alen / 2)
		while (--len >= 0)
			ps_rr(stack->a, stack->alen, 'a', stack);
	else
	{
		len = stack->alen - len;
		while (--len >= 0)
			ps_r(stack->a, stack->alen, 'a', stack);
	}
}

void	sort_less_10(t_stack *stack)
{
	int *a;

	a = stack->a;
	while (!(check_sort(a, stack->alen, stack->alen, 'a') && stack->blen == 0))
	{
		if (stack->alen == 3)
		{
			sort_only_3(stack);
			while (stack->blen > 0)
				ps_p(stack, 'a', 1);
		}
		else if (a[stack->alen - 1] == ft_min(a, stack->alen))
			ps_p(stack, 'b', 1);
		else
			sort_less_10_dop(stack, a);
	}
}

void	parce_swap(t_stack *stack, int ac, char **str)
{
	stack->alen = ac + 1;
	stack->blen = 0;
	stack->print = 1;
	if (check(ac, str) == -1)
	{
		ft_putstr("Error\n");
		return ;
	}
	stack->blen = 0;
	stack->b = (int*)ft_memalloc(sizeof(int) * ac);
	stack->a = reader(ac, str);
	if (check_copie(stack->a, stack->alen) == 0)
		ft_putstr("Error\n");
	else if (stack->alen > 13)
		sort_stacka(stack, stack->alen);
	else
		sort_less_10(stack);
	free(stack->a);
	free(stack->b);
}

int		main(int ac, char **av)
{
	t_stack	stack;
	char	**str;
	int		i;

	i = 1;
	if (--ac == 0)
		return (0);
	else if (ac == 1)
	{
		ac = ft_w(av[1], 32);
		if (ac == 1)
			return (0);
		i = 0;
		str = ft_strsplit(av[1], 32, ac);
	}
	else
		str = ++av;
	parce_swap(&stack, --ac, str);
	if (i == 0)
	{
		while (str[i] != NULL)
			free(str[i++]);
		free(str);
	}
	return (0);
}
