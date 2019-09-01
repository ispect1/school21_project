/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 02:29:46 by ljonnel-          #+#    #+#             */
/*   Updated: 2019/05/19 02:29:47 by ljonnel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(int *a, int len, int true_len, char c)
{
	if (c == 'a')
		while (--len > 0)
			if (a[true_len - len] > a[true_len - len - 1])
				return (0);
	if (c == 'b')
		while (--len > 0)
			if (a[true_len - len] < a[true_len - len - 1])
				return (0);
	return (1);
}

void	sort_3_or_2_param2(t_stack *stack, int *elem)
{
	if (elem[0] < elem[1] && elem[0] > elem[2])
	{
		ps_p(stack, 'b', 2);
		ps_r(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'a', 2);
		ps_rr(stack->a, stack->alen, 'a', stack);
	}
	else if (elem[0] < elem[1] && elem[0] < elem[2])
	{
		ps_p(stack, 'b', 1);
		ps_s(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'a', 1);
	}
	else if (elem[0] > elem[1] && elem[0] > elem[2])
	{
		ps_r(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'b', 2);
		ps_rr(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'a', 2);
	}
	else if (elem[0] > elem[1] && elem[0] < elem[2])
		ps_s(stack->a, stack->alen, 'a', stack);
}

void	sort_3_or_2_param1(t_stack *stack, int len, int n)
{
	int elem[3];

	if (n == 2)
	{
		if (stack->a[len - 1] > stack->a[len - 2])
			ps_s(stack->a, len, 'a', stack);
		return ;
	}
	elem[0] = stack->a[len - 1];
	elem[1] = stack->a[len - 2];
	elem[2] = stack->a[len - 3];
	if (elem[0] < elem[1] && elem[1] < elem[2])
		return ;
	else if (elem[0] > elem[1] && elem[1] > elem[2])
	{
		ps_s(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'b', 2);
		ps_r(stack->a, stack->alen, 'a', stack);
		ps_p(stack, 'a', 2);
		ps_rr(stack->a, stack->alen, 'a', stack);
	}
	else
		sort_3_or_2_param2(stack, elem);
}

void	quick_sort(int *a, int n)
{
	int	index_pivot;

	index_pivot = partition(a, n);
	if (index_pivot > 0)
		quick_sort(a, index_pivot);
	if (index_pivot + 1 < n)
		quick_sort(a + index_pivot + 1, n - (index_pivot + 1));
}

int		partition(int *a, int n)
{
	int pivot;
	int i;
	int j;

	if (n <= 1)
		return (0);
	pivot = a[n - 1];
	i = 0;
	j = n - 2;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] >= pivot && j >= 0)
			j--;
		if (i < j)
			ft_swap(&a[i++], &a[j--]);
	}
	ft_swap(&a[i], &a[n - 1]);
	return (i);
}
